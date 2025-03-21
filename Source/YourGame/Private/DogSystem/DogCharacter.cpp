#include "DogSystem/DogCharacter.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

ADogCharacter::ADogCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
    InteractionRadius = 200.0f;
    FollowDistance = 150.0f;
    CurrentState = EDogState::Idle;
}

void ADogCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void ADogCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    UpdateBehavior(DeltaTime);
}

void ADogCharacter::InteractWithPlayer(ACharacter* Player)
{
    if (!Player || !IsPlayerInRange())
        return;

    switch (CurrentState)
    {
        case EDogState::Idle:
            UpdateDogState(EDogState::Following);
            break;
        case EDogState::Following:
            UpdateDogState(EDogState::Sitting);
            break;
        default:
            UpdateDogState(EDogState::Idle);
            break;
    }
}

void ADogCharacter::UpdateDogState(EDogState NewState)
{
    CurrentState = NewState;
}

void ADogCharacter::UpdateBehavior(float DeltaTime)
{
    ACharacter* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
    if (!Player)
        return;

    switch (CurrentState)
    {
        case EDogState::Following:
            // Implement following logic
            break;
        case EDogState::Sitting:
            // Implement sitting behavior
            break;
        default:
            break;
    }
}

bool ADogCharacter::IsPlayerInRange() const
{
    ACharacter* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
    if (!Player)
        return false;

    float Distance = FVector::Distance(GetActorLocation(), Player->GetActorLocation());
    return Distance <= InteractionRadius;
}
