#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DogSystem/DogTypes.h"
#include "HuntingTargetInterface.generated.h"

// Этот класс не нужно изменять.
UINTERFACE(MinimalAPI)
class UHuntingTargetInterface : public UInterface
{
    GENERATED_BODY()
};

/**
 * Интерфейс для объектов, с которыми может взаимодействовать собака при охоте
 */
class YOURGAME_API IHuntingTargetInterface
{
    GENERATED_BODY()

public:
    /**
     * Получить тип животного для охоты
     * @return Тип животного
     */
    UFUNCTION(BlueprintNativeEvent, Category = "Hunting")
    EHuntingAnimalType GetAnimalType() const;

    /**
     * Проверить, может ли собака определенной породы взаимодействовать с этим животным
     * @param DogBreed Порода собаки
     * @return True, если собака может взаимодействовать с этим животным
     */
    UFUNCTION(BlueprintNativeEvent, Category = "Hunting")
    bool CanBeTrackedByDog(EDogBreed DogBreed) const;

    /**
     * Проверить, может ли собака определенной породы принести это животное
     * @param DogBreed Порода собаки
     * @return True, если собака может принести это животное
     */
    UFUNCTION(BlueprintNativeEvent, Category = "Hunting")
    bool CanBeFetchedByDog(EDogBreed DogBreed) const;

    /**
     * Получить силу запаха животного (для отслеживания)
     * @return Сила запаха (0.0 - 1.0)
     */
    UFUNCTION(BlueprintNativeEvent, Category = "Hunting")
    float GetScentStrength() const;

    /**
     * Получить вес животного (для определения, может ли собака его нести)
     * @return Вес в килограммах
     */
    UFUNCTION(BlueprintNativeEvent, Category = "Hunting")
    float GetWeight() const;

    /**
     * Вызывается, когда собака обнаруживает животное
     * @param Dog Собака, которая обнаружила животное
     */
    UFUNCTION(BlueprintNativeEvent, Category = "Hunting")
    void OnDetectedByDog(class ADogCharacter* Dog);

    /**
     * Вызывается, когда собака указывает на животное (для пойнтера)
     * @param Dog Собака, которая указывает на животное
     */
    UFUNCTION(BlueprintNativeEvent, Category = "Hunting")
    void OnPointedByDog(class ADogCharacter* Dog);

    /**
     * Вызывается, когда собака подбирает животное
     * @param Dog Собака, которая подбирает животное
     * @return True, если подбор успешен
     */
    UFUNCTION(BlueprintNativeEvent, Category = "Hunting")
    bool OnFetchedByDog(class ADogCharacter* Dog);
};
