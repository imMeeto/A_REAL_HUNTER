#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "DogSystem/DogTypes.h"
#include "DogAIController.generated.h"

/**
 * Контроллер ИИ для собаки
 */
UCLASS()
class YOURGAME_API ADogAIController : public AAIController
{
    GENERATED_BODY()

public:
    ADogAIController();

    virtual void BeginPlay() override;
    virtual void OnPossess(APawn* InPawn) override;
    virtual void Tick(float DeltaTime) override;

    /**
     * Выполнить команду
     * @param Command Команда для выполнения
     * @param TargetLocation Целевая локация (если применимо)
     * @param TargetActor Целевой актор (если применимо)
     */
    UFUNCTION(BlueprintCallable, Category = "Dog AI")
    void ExecuteCommand(EDogCommand Command, FVector TargetLocation = FVector::ZeroVector, AActor* TargetActor = nullptr);

    /**
     * Прервать текущую команду
     */
    UFUNCTION(BlueprintCallable, Category = "Dog AI")
    void CancelCommand();

    /**
     * Проверить, выполняет ли собака команду
     * @return True, если собака выполняет команду
     */
    UFUNCTION(BlueprintCallable, Category = "Dog AI")
    bool IsExecutingCommand() const;

    /**
     * Получить текущую команду
     * @return Текущая команда
     */
    UFUNCTION(BlueprintCallable, Category = "Dog AI")
    EDogCommand GetCurrentCommand() const;

    /**
     * Установить целевую локацию для поиска
     * @param Location Целевая локация
     */
    UFUNCTION(BlueprintCallable, Category = "Dog AI")
    void SetSearchLocation(FVector Location);

    /**
     * Установить целевой актор для отслеживания
     * @param Actor Целевой актор
     */
    UFUNCTION(BlueprintCallable, Category = "Dog AI")
    void SetTrackingTarget(AActor* Actor);

    /**
     * Установить целевой актор для подбора
     * @param Actor Целевой актор
     */
    UFUNCTION(BlueprintCallable, Category = "Dog AI")
    void SetFetchTarget(AActor* Actor);

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog AI")
    float SearchRadius;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog AI")
    float PointingDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog AI")
    float TrackingUpdateInterval;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog AI")
    UBehaviorTree* DogBehaviorTree;

private:
    UPROPERTY()
    class ADogCharacter* DogCharacter;

    UPROPERTY()
    EDogCommand CurrentCommand;

    UPROPERTY()
    FVector SearchTargetLocation;

    UPROPERTY()
    AActor* TrackingTargetActor;

    UPROPERTY()
    AActor* FetchTargetActor;

    UPROPERTY()
    bool bIsExecutingCommand;

    float TrackingTimer;

    void UpdateBehaviorBasedOnCommand();
    void ExecuteComeCommand();
    void ExecuteSitCommand();
    void ExecuteLieDownCommand();
    void ExecuteSearchCommand();
    void ExecuteTrackCommand();
    void ExecuteFetchCommand();
    void ExecutePointCommand();
    void ExecuteRestCommand();
};
