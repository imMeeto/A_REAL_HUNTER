#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DogCharacter.generated.h"

UENUM(BlueprintType)
enum class EDogState : uint8
{
    Idle,
    Following,
    Playing,
    Sitting,
    Sleeping
};

UCLASS()
class YOURGAME_API ADogCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ADogCharacter();

    virtual void Tick(float DeltaTime) override;
    virtual void BeginPlay() override;

    UFUNCTION(BlueprintCallable, Category = "Dog System")
    void InteractWithPlayer(class ACharacter* Player);

    UFUNCTION(BlueprintCallable, Category = "Dog System")
    void UpdateDogState(EDogState NewState);

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog System")
    float InteractionRadius;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog System")
    EDogState CurrentState;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog System")
    float FollowDistance;

private:
    void UpdateBehavior(float DeltaTime);
    bool IsPlayerInRange() const;
};
