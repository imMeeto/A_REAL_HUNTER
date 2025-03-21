#include "DogSystem/DogAIController.h"
#include "DogSystem/DogCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/AIPerceptionComponent.h"
#include "Navigation/PathFollowingComponent.h"

// Ключи для Blackboard
const FName BB_IsExecutingCommand = TEXT("IsExecutingCommand");
const FName BB_CurrentCommand = TEXT("CurrentCommand");
const FName BB_TargetLocation = TEXT("TargetLocation");
const FName BB_TargetActor = TEXT("TargetActor");
const FName BB_OwnerActor = TEXT("OwnerActor");
const FName BB_SearchRadius = TEXT("SearchRadius");
const FName BB_PointingDistance = TEXT("PointingDistance");

ADogAIController::ADogAIController()
{
    PrimaryActorTick.bCanEverTick = true;

    // Настройка компонентов восприятия
    PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent"));

    // Инициализация переменных
    SearchRadius = 1000.0f;
    PointingDistance = 200.0f;
    TrackingUpdateInterval = 0.5f;
    bIsExecutingCommand = false;
    CurrentCommand = EDogCommand::Come;
    TrackingTimer = 0.0f;
}

void ADogAIController::BeginPlay()
{
    Super::BeginPlay();

    // Инициализация Blackboard и запуск BehaviorTree, если они доступны
    if (DogBehaviorTree && UseBlackboard(DogBehaviorTree->BlackboardAsset, Blackboard))
    {
        Blackboard->SetValueAsBool(BB_IsExecutingCommand, false);
        Blackboard->SetValueAsEnum(BB_CurrentCommand, static_cast<uint8>(EDogCommand::Come));
        Blackboard->SetValueAsFloat(BB_SearchRadius, SearchRadius);
        Blackboard->SetValueAsFloat(BB_PointingDistance, PointingDistance);

        RunBehaviorTree(DogBehaviorTree);
    }
}

void ADogAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    DogCharacter = Cast<ADogCharacter>(InPawn);
    if (DogCharacter && Blackboard)
    {
        Blackboard->SetValueAsObject(BB_OwnerActor, DogCharacter->GetOwner());
    }
}

void ADogAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bIsExecutingCommand && DogCharacter)
    {
        // Обновление поведения на основе текущей команды
        UpdateBehaviorBasedOnCommand();

        // Обновление таймера отслеживания
        if (CurrentCommand == EDogCommand::Track && TrackingTargetActor)
        {
            TrackingTimer += DeltaTime;
            if (TrackingTimer >= TrackingUpdateInterval)
            {
                TrackingTimer = 0.0f;
                // Обновление пути к цели отслеживания
                if (Blackboard)
                {
                    Blackboard->SetValueAsObject(BB_TargetActor, TrackingTargetActor);
                    Blackboard->SetValueAsVector(BB_TargetLocation, TrackingTargetActor->GetActorLocation());
                }
            }
        }
    }
}

void ADogAIController::ExecuteCommand(EDogCommand Command, FVector TargetLocation, AActor* TargetActor)
{
    if (!DogCharacter)
    {
        return;
    }

    // Проверка усталости собаки
    if (DogCharacter->IsTooTired() && Command != EDogCommand::Rest && Command != EDogCommand::Come)
    {
        // Собака слишком устала для выполнения команды
        return;
    }

    CurrentCommand = Command;
    bIsExecutingCommand = true;
    SearchTargetLocation = TargetLocation;

    if (TargetActor)
    {
        if (Command == EDogCommand::Track)
        {
            TrackingTargetActor = TargetActor;
        }
        else if (Command == EDogCommand::Fetch)
        {
            FetchTargetActor = TargetActor;
        }
    }

    // Обновление Blackboard
    if (Blackboard)
    {
        Blackboard->SetValueAsBool(BB_IsExecutingCommand, true);
        Blackboard->SetValueAsEnum(BB_CurrentCommand, static_cast<uint8>(Command));
        Blackboard->SetValueAsVector(BB_TargetLocation, TargetLocation);
        Blackboard->SetValueAsObject(BB_TargetActor, TargetActor);
    }

    // Выполнение соответствующей команды
    switch (Command)
    {
        case EDogCommand::Come:
            ExecuteComeCommand();
            break;
        case EDogCommand::Sit:
            ExecuteSitCommand();
            break;
        case EDogCommand::LieDown:
            ExecuteLieDownCommand();
            break;
        case EDogCommand::Search:
            ExecuteSearchCommand();
            break;
        case EDogCommand::Track:
            ExecuteTrackCommand();
            break;
        case EDogCommand::Fetch:
            ExecuteFetchCommand();
            break;
        case EDogCommand::Point:
            ExecutePointCommand();
            break;
        case EDogCommand::Rest:
            ExecuteRestCommand();
            break;
    }
}

void ADogAIController::CancelCommand()
{
    bIsExecutingCommand = false;
    if (Blackboard)
    {
        Blackboard->SetValueAsBool(BB_IsExecutingCommand, false);
    }

    // Сброс целей
    TrackingTargetActor = nullptr;
    FetchTargetActor = nullptr;

    // Переход в состояние бездействия
    if (DogCharacter)
    {
        DogCharacter->UpdateDogState(EDogState::Idle);
    }
}

bool ADogAIController::IsExecutingCommand() const
{
    return bIsExecutingCommand;
}

EDogCommand ADogAIController::GetCurrentCommand() const
{
    return CurrentCommand;
}

void ADogAIController::SetSearchLocation(FVector Location)
{
    SearchTargetLocation = Location;
    if (Blackboard && bIsExecutingCommand && CurrentCommand == EDogCommand::Search)
    {
        Blackboard->SetValueAsVector(BB_TargetLocation, Location);
    }
}

void ADogAIController::SetTrackingTarget(AActor* Actor)
{
    TrackingTargetActor = Actor;
    if (Blackboard && bIsExecutingCommand && CurrentCommand == EDogCommand::Track)
    {
        Blackboard->SetValueAsObject(BB_TargetActor, Actor);
        if (Actor)
        {
            Blackboard->SetValueAsVector(BB_TargetLocation, Actor->GetActorLocation());
        }
    }
}

void ADogAIController::SetFetchTarget(AActor* Actor)
{
    FetchTargetActor = Actor;
    if (Blackboard && bIsExecutingCommand && CurrentCommand == EDogCommand::Fetch)
    {
        Blackboard->SetValueAsObject(BB_TargetActor, Actor);
        if (Actor)
        {
            Blackboard->SetValueAsVector(BB_TargetLocation, Actor->GetActorLocation());
        }
    }
}

void ADogAIController::UpdateBehaviorBasedOnCommand()
{
    // Обновление поведения на основе текущей команды
    // Это будет вызываться каждый тик, пока выполняется команда
}

void ADogAIController::ExecuteComeCommand()
{
    if (!DogCharacter)
    {
        return;
    }

    DogCharacter->UpdateDogState(EDogState::Following);

    // Получение владельца собаки (игрока)
    AActor* Owner = DogCharacter->GetOwner();
    if (Owner && Blackboard)
    {
        Blackboard->SetValueAsObject(BB_TargetActor, Owner);
        Blackboard->SetValueAsVector(BB_TargetLocation, Owner->GetActorLocation());
    }
}

void ADogAIController::ExecuteSitCommand()
{
    if (!DogCharacter)
    {
        return;
    }

    DogCharacter->UpdateDogState(EDogState::Sitting);
}

void ADogAIController::ExecuteLieDownCommand()
{
    if (!DogCharacter)
    {
        return;
    }

    DogCharacter->UpdateDogState(EDogState::Lying);
}

void ADogAIController::ExecuteSearchCommand()
{
    if (!DogCharacter)
    {
        return;
    }

    DogCharacter->UpdateDogState(EDogState::Searching);
}

void ADogAIController::ExecuteTrackCommand()
{
    if (!DogCharacter)
    {
        return;
    }

    DogCharacter->UpdateDogState(EDogState::Tracking);
}

void ADogAIController::ExecuteFetchCommand()
{
    if (!DogCharacter)
    {
        return;
    }

    DogCharacter->UpdateDogState(EDogState::Fetching);
}

void ADogAIController::ExecutePointCommand()
{
    if (!DogCharacter)
    {
        return;
    }

    DogCharacter->UpdateDogState(EDogState::Pointing);
}

void ADogAIController::ExecuteRestCommand()
{
    if (!DogCharacter)
    {
        return;
    }

    DogCharacter->UpdateDogState(EDogState::Sleeping);
}
