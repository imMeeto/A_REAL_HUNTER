#pragma once

#include "CoreMinimal.h"
#include "DogTypes.generated.h"

/**
 * Перечисление пород собак
 */
UENUM(BlueprintType)
enum class EDogBreed : uint8
{
    Retriever UMETA(DisplayName = "Ретривер"),
    Hound UMETA(DisplayName = "Гончая"),
    Pointer UMETA(DisplayName = "Немецкий пойнтер")
};

/**
 * Перечисление состояний собаки
 */
UENUM(BlueprintType)
enum class EDogState : uint8
{
    Idle UMETA(DisplayName = "Бездействие"),
    Following UMETA(DisplayName = "Следование"),
    Sitting UMETA(DisplayName = "Сидение"),
    Lying UMETA(DisplayName = "Лежание"),
    Searching UMETA(DisplayName = "Поиск"),
    Tracking UMETA(DisplayName = "Отслеживание"),
    Fetching UMETA(DisplayName = "Подбор добычи"),
    Pointing UMETA(DisplayName = "Указание"),
    Tired UMETA(DisplayName = "Усталость"),
    Sleeping UMETA(DisplayName = "Сон")
};

/**
 * Перечисление команд собаки
 */
UENUM(BlueprintType)
enum class EDogCommand : uint8
{
    Come UMETA(DisplayName = "Ко мне"),
    Sit UMETA(DisplayName = "Сидеть"),
    LieDown UMETA(DisplayName = "Лежать"),
    Search UMETA(DisplayName = "Искать"),
    Track UMETA(DisplayName = "След"),
    Fetch UMETA(DisplayName = "Принеси"),
    Point UMETA(DisplayName = "Указать"),
    Rest UMETA(DisplayName = "Отдыхать")
};

/**
 * Перечисление типов животных для охоты
 */
UENUM(BlueprintType)
enum class EHuntingAnimalType : uint8
{
    SmallBird UMETA(DisplayName = "Мелкая птица"),
    LargeBird UMETA(DisplayName = "Крупная птица"),
    SmallMammal UMETA(DisplayName = "Мелкое млекопитающее"),
    MediumMammal UMETA(DisplayName = "Среднее млекопитающее"),
    LargeMammal UMETA(DisplayName = "Крупное млекопитающее")
};

/**
 * Структура для навыков собаки
 */
USTRUCT(BlueprintType)
struct FDogSkills
{
    GENERATED_BODY()

    // Общие навыки
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog Skills")
    float StaminaEfficiency;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog Skills")
    float MovementSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog Skills")
    float TrackingAbility;

    // Специфические навыки для ретривера
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog Skills|Retriever")
    float SwimmingAbility;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog Skills|Retriever")
    float FetchingSpeed;

    // Специфические навыки для гончей
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog Skills|Hound")
    float TrackingDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog Skills|Hound")
    float ScentDetectionRange;

    // Специфические навыки для пойнтера
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog Skills|Pointer")
    float PointingAccuracy;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog Skills|Pointer")
    float BirdDetectionRange;

    FDogSkills()
        : StaminaEfficiency(1.0f)
        , MovementSpeed(1.0f)
        , TrackingAbility(1.0f)
        , SwimmingAbility(1.0f)
        , FetchingSpeed(1.0f)
        , TrackingDistance(1.0f)
        , ScentDetectionRange(1.0f)
        , PointingAccuracy(1.0f)
        , BirdDetectionRange(1.0f)
    {
    }
};

/**
 * Структура для опыта собаки
 */
USTRUCT(BlueprintType)
struct FDogExperience
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog Experience")
    int32 Level;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog Experience")
    float CurrentExperience;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog Experience")
    float ExperienceForNextLevel;

    FDogExperience()
        : Level(1)
        , CurrentExperience(0.0f)
        , ExperienceForNextLevel(100.0f)
    {
    }
};

/**
 * Структура для статистики собаки
 */
USTRUCT(BlueprintType)
struct FDogStats
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog Stats")
    float Loyalty;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog Stats")
    float Fatigue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog Stats")
    float FatigueRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog Stats")
    float RestRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog Stats")
    float MaxStamina;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog Stats")
    float CurrentStamina;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog Stats")
    float StaminaRecoveryRate;

    FDogStats()
        : Loyalty(50.0f)
        , Fatigue(0.0f)
        , FatigueRate(0.1f)
        , RestRate(0.2f)
        , MaxStamina(100.0f)
        , CurrentStamina(100.0f)
        , StaminaRecoveryRate(5.0f)
    {
    }
};
