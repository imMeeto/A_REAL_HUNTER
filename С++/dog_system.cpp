
/*
Расширенная разработка механики
оздание класса собаки
Добавлены новые параметры: опыт (Experience), необходимый опыт для повышения уровня (RequiredExperienceForNextLevel) и специфические навыки для каждой породы.  */

// Dog.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Dog.generated.h"

UENUM(BlueprintType)
enum class EDogBreed : uint8 {
    Retriever,
    Hound,
    Terrier
};

UENUM(BlueprintType)
enum class EDogCommand : uint8 {
    Search,  // Искать дичь
    Track,   // Искать следы
    Come,    // Ко мне
    Sit,     // Сидеть
    LieDown, // Лежать
    Fetch,   // Принести добычу
    Guard    // Защитить игрока
};

UCLASS()
class THEHUNTER_API ADog : public ACharacter {
    GENERATED_BODY()

public:
    ADog();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog")
    EDogBreed Breed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog")
    float Loyalty; // Лояльность (0-100)

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog")
    float Fatigue; // Усталость (0-100)

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog")
    int Level; // Уровень прокачки

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog")
    float Experience; // Опыт

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog")
    float RequiredExperienceForNextLevel; // Необходимый опыт для следующего уровня

    UFUNCTION(BlueprintCallable, Category = "Dog")
    void Feed();

    UFUNCTION(BlueprintCallable, Category = "Dog")
    void Praise();

    UFUNCTION(BlueprintCallable, Category = "Dog")
    void Rest();

    UFUNCTION(BlueprintCallable, Category = "Dog")
    void ExecuteCommand(EDogCommand Command);

    UFUNCTION(BlueprintCallable, Category = "Dog")
    void GainExperience(float Amount);

    UFUNCTION(BlueprintCallable, Category = "Dog")
    void LevelUp();

protected:
    virtual void BeginPlay() override;

private:
    float FatigueRate = 0.1f; // Скорость увеличения усталости
    float RestRate = 0.2f;    // Скорость восстановления

    void SearchForPrey();
    void TrackAnimal();
    void ComeToPlayer();
    void Sit();
    void LieDown();
    void FetchPrey(); // Принести добычу
    void GuardPlayer(); // Защитить игрока
};  

/* Реализация команд собаки
Расширены команды для каждой породы: */

// Dog.cpp
#include "Dog.h"

void ADog::ExecuteCommand(EDogCommand Command) {
    switch (Command) {
        case EDogCommand::Search:
            SearchForPrey();
            break;
        case EDogCommand::Track:
            TrackAnimal();
            break;
        case EDogCommand::Come:
            ComeToPlayer();
            break;
        case EDogCommand::Sit:
            Sit();
            break;
        case EDogCommand::LieDown:
            LieDown();
            break;
        case EDogCommand::Fetch:
            FetchPrey();
            break;
        case EDogCommand::Guard:
            GuardPlayer();
            break;
    }
}

void ADog::SearchForPrey() {
    UE_LOG(LogTemp, Warning, TEXT("Dog is searching for prey."));
}

void ADog::TrackAnimal() {
    UE_LOG(LogTemp, Warning, TEXT("Dog is tracking animal."));
}

void ADog::ComeToPlayer() {
    UE_LOG(LogTemp, Warning, TEXT("Dog is coming to player."));
}

void ADog::Sit() {
    UE_LOG(LogTemp, Warning, TEXT("Dog is sitting."));
}

void ADog::LieDown() {
    UE_LOG(LogTemp, Warning, TEXT("Dog is lying down."));
}

void ADog::FetchPrey() {
    if (Breed == EDogBreed::Retriever) {
        UE_LOG(LogTemp, Warning, TEXT("Retriever is fetching prey."));
    } else {
        UE_LOG(LogTemp, Warning, TEXT("This dog cannot fetch prey."));
    }
}

void ADog::GuardPlayer() {
    if (Breed == EDogBreed::Terrier) {
        UE_LOG(LogTemp, Warning, TEXT("Terrier is guarding the player."));
    } else {
        UE_LOG(LogTemp, Warning, TEXT("This dog cannot guard."));
    }
}  

/* Система лояльности и усталости
Добавлена проверка состояния собаки перед выполнением команд:  */

void ADog::Feed() {
    if (Loyalty < 100) {
        Loyalty += 10;
        Fatigue -= 5;
    }
    UE_LOG(LogTemp, Warning, TEXT("Dog has been fed. Loyalty: %f, Fatigue: %f"), Loyalty, Fatigue);
}

void ADog::Praise() {
    if (Loyalty < 100) {
        Loyalty += 5;
    }
    UE_LOG(LogTemp, Warning, TEXT("Dog has been praised. Loyalty: %f"), Loyalty);
}

void ADog::Rest() {
    if (Fatigue > 0) {
        Fatigue -= RestRate;
    }
    UE_LOG(LogTemp, Warning, TEXT("Dog is resting. Fatigue: %f"), Fatigue);
}

void ADog::UpdateFatigue(float DeltaTime) {
    if (IsActive) {
        Fatigue += DeltaTime * FatigueRate;
    } else {
        Fatigue -= DeltaTime * RestRate;
    }

    if (Fatigue < 0) Fatigue = 0;
    if (Fatigue > 100) Fatigue = 100;
}  

/*Система опыта
Добавлена возможность повышения уровня через набор опыта:  */

void ADog::GainExperience(float Amount) {
    Experience += Amount;
    UE_LOG(LogTemp, Warning, TEXT("Dog gained %f experience. Total: %f"), Amount, Experience);

    if (Experience >= RequiredExperienceForNextLevel) {
        LevelUp();
    }
}

void ADog::LevelUp() {
    Level++;
    FatigueRate *= 0.9f; // Уменьшаем скорость усталости
    RestRate *= 1.1f;    // Увеличиваем скорость восстановления
    RequiredExperienceForNextLevel *= 1.5f; // Увеличиваем требуемый опыт

    UE_LOG(LogTemp, Warning, TEXT("Dog leveled up! New level: %d"), Level);
}  

/* Управление несколькими собаками
Реализована возможность автоматического выбора наиболее подходящей собаки для выполнения команды: */

// PlayerCharacter.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class THEHUNTER_API APlayerCharacter : public ACharacter {
    GENERATED_BODY()

public:
    APlayerCharacter();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dogs")
    TArray<ADog*> Dogs;

    UFUNCTION(BlueprintCallable, Category = "Dogs")
    void SwitchDog(int Index);

    UFUNCTION(BlueprintCallable, Category = "Dogs")
    ADog* GetBestDogForCommand(EDogCommand Command);

protected:
    virtual void BeginPlay() override;

private:
    int CurrentDogIndex = 0;
};

// PlayerCharacter.cpp
#include "PlayerCharacter.h"
#include "Dog.h"

ADog* APlayerCharacter::GetBestDogForCommand(EDogCommand Command) {
    for (ADog* Dog : Dogs) {
        if (Dog->Fatigue < 50) { // Выбираем собаку с низкой усталостью
            switch (Command) {
                case EDogCommand::Fetch:
                    if (Dog->Breed == EDogBreed::Retriever) return Dog;
                    break;
                case EDogCommand::Guard:
                    if (Dog->Breed == EDogBreed::Terrier) return Dog;
                    break;
                default:
                    return Dog;
            }
        }
    }
    return nullptr; // Если нет подходящих собак
}

void APlayerCharacter::SwitchDog(int Index) {
    if (Index >= 0 && Index < Dogs.Num()) {
        if (Dogs[CurrentDogIndex]->Fatigue < 80) {
            CurrentDogIndex = Index;
            UE_LOG(LogTemp, Warning, TEXT("Switched to dog %d"), Index);
        } else {
            UE_LOG(LogTemp, Warning, TEXT("Dog %d is too tired to switch!"), CurrentDogIndex);
        }
    }
}  

/* Инвентарь и рюкзаки
Добавлена поддержка рюкзаков для собак: */

// DogInventory.h
#pragma once

#include "CoreMinimal.h"
#include "DogInventory.generated.h"

UCLASS()
class THEHUNTER_API UDogInventory : public UObject {
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    TArray<UObject*> Items;

    UFUNCTION(BlueprintCallable, Category = "Inventory")
    void AddItem(UObject* Item);

    UFUNCTION(BlueprintCallable, Category = "Inventory")
    void RemoveItem(UObject* Item);
};

// DogInventory.cpp
#include "DogInventory.h"

void UDogInventory::AddItem(UObject* Item) {
    Items.Add(Item);
    UE_LOG(LogTemp, Warning, TEXT("Item added to dog's inventory."));
}

void UDogInventory::RemoveItem(UObject* Item) {
    Items.Remove(Item);
    UE_LOG(LogTemp, Warning, TEXT("Item removed from dog's inventory."));
}