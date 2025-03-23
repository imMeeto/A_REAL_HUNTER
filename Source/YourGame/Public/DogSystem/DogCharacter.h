#pragma once
#include "Include/DogSystem/DogTypes.h"
#include "Include/DogSystem/HuntingTargetInterface.h"

class YOURGAME_API ADogCharacter : public AActor
{
    GENERATED_BODY()

public:
    static FText GetDogStateText(EDogState State);

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog")
    EDogState CurrentState;

private:
};
