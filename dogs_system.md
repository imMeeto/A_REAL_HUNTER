# Расширенный план разработки механики охоты с собакой в **theHunter: Call of the Wild**

---

## **Содержание**
- [Расширенный план разработки механики охоты с собакой в **theHunter: Call of the Wild**](#расширенный-план-разработки-механики-охоты-с-собакой-в-thehunter-call-of-the-wild)
  - [**Содержание**](#содержание)
  - [**1. Введение**](#1-введение)
  - [**2. О породах и способностях собак**](#2-о-породах-и-способностях-собак)
  - [**3. Опыт**](#3-опыт)
    - [**3.1. Выносливость**](#31-выносливость)
    - [**3.2. Ленты опыта**](#32-ленты-опыта)
    - [**3.3. Награды за опыт**](#33-награды-за-опыт)
  - [**4. Награды за уровни собак**](#4-награды-за-уровни-собак)
  - [**5. Система навыков**](#5-система-навыков)
    - [**5.1. Навыки преданности**](#51-навыки-преданности)
  - [**6. Управление собакой**](#6-управление-собакой)
    - [**6.1. Команды собаке**](#61-команды-собаке)
    - [**6.2. Иконки реакции собаки**](#62-иконки-реакции-собаки)
  - [**7. Ретривер**](#7-ретривер)
    - [**7.1. Вариации**](#71-вариации)
    - [**7.2. Кого может приносить**](#72-кого-может-приносить)
    - [**7.3. Навыки ретривера**](#73-навыки-ретривера)
    - [**7.4. Меню команд ретривера**](#74-меню-команд-ретривера)
  - [**8. Гончая**](#8-гончая)
    - [**8.1. Вариации**](#81-вариации)
    - [**8.2. Как выслеживать**](#82-как-выслеживать)
    - [**8.3. Навыки гончей**](#83-навыки-гончей)
    - [**8.4. Меню команд гончей**](#84-меню-команд-гончей)
  - [**9. Немецкий пойнтер**](#9-немецкий-пойнтер)
    - [**9.1. Вариации**](#91-вариации)
    - [**9.2. Кого может выслеживать**](#92-кого-может-выслеживать)
    - [**9.3. Навыки немецкого пойнтера**](#93-навыки-немецкого-пойнтера)
    - [**9.4. Меню команд немецкого пойнтера**](#94-меню-команд-немецкого-пойнтера)
  - [**10. Другие факты о собаках**](#10-другие-факты-о-собаках)
  - [**11. Снаряжение**](#11-снаряжение)
    - [**11.1. Ошейники**](#111-ошейники)
    - [**11.2. GPS маяк для собаки**](#112-gps-маяк-для-собаки)
    - [**11.3. Жилеты для собак**](#113-жилеты-для-собак)
    - [**11.4. Шейный платок для собак**](#114-шейный-платок-для-собак)
    - [**11.5. Использование собачьего снаряжения**](#115-использование-собачьего-снаряжения)
  - [**12. Лакомства для собак**](#12-лакомства-для-собак)
  - [**13. Рюкзаки для собак**](#13-рюкзаки-для-собак)
    - [**13.1. Варианты рюкзаков**](#131-варианты-рюкзаков)
    - [**13.2. Использование рюкзаков для собак**](#132-использование-рюкзаков-для-собак)
  - [**14. Изображения ретривера**](#14-изображения-ретривера)
  - [**15. Изображения гончей**](#15-изображения-гончей)

---

## **1. Введение**
**Собаки в игре** — это скорее опыт и удобство, а не изменяющее процесс игры дополнение к *theHunter Classic*. Собака не оказывает реального влияния на миссии или соревнования, поскольку выслеживать и стрелять по-прежнему должен игрок.

> Разработчики рассказали, почему были выбраны конкретные, а не общие типы собак:  
> "Когда мы читали о собаках на форумах и спрашивали наших доверенных охотников, первым, что упоминалось почти всегда, это собака для поиска птиц. Исключительно из-за этого было решено начать именно с неё. Многие также предлагали собаку, более универсальную, которая могла бы, например, не только выслеживать, но и приносить добычу. Хотя мы рассматривали возможность создания собак, которые могли бы выполнять несколько задач, быстро стало очевидно, что надо разрабатывать простой в использовании пользовательский интерфейс. Система для собаки, которая могла бы выслеживать, ловить, подносить и участвовать в загонной охоте, была бы невозможна. Также было трудно найти подходящую породу, которая подошла бы на роль столь ​​разносторонне одаренной собаки. Поэтому мы решили сосредоточиться на специализированных собаках."

---

## **2. О породах и способностях собак**
На странице Wiki упоминаются разные породы собак:
- **Ретриверы**: Специализируются на поиске и подносе дичи.
- **Гончие**: Выслеживают животных по следам.
- **Немецкий пойнтер**: Используется для выслеживания и указания местоположения дичи.

Каждая порода имеет уникальные характеристики, такие как скорость выполнения задач, эффективность в разных условиях (например, ретриверы лучше работают в воде) и визуальные различия (модели, текстуры).

---

## **3. Опыт**
### **3.1. Выносливость**
Выносливость собаки определяет, как долго она может выполнять команды без отдыха. Чем выше уровень собаки, тем медленнее растёт её усталость.

- **Механика:** Уровень усталости увеличивается со временем выполнения команд и снижается при отдыхе.
- **Формула:**  

Fatigue += DeltaTime * FatigueRate;
Fatigue -= DeltaTime * RestRate (если собака в состоянии покоя);  

---

### **3.2. Ленты опыта**
Опыт собаки повышается за выполнение различных действий:
- Нахождение дичи.
- Отслеживание следов.
- Помощь в бое.

Лента опыта разделена на уровни, каждый из которых предоставляет новые возможности.

### **3.3. Награды за опыт**
При достижении нового уровня собака получает награды:
- Увеличение характеристик (скорость, выносливость).
- Доступ к новым командам.
- Улучшение существующих навыков.

---

## **4. Награды за уровни собак**
При повышении уровня собака получает следующие бонусы:
- Уменьшение скорости усталости.
- Увеличение скорости восстановления.
- Доступ к новому снаряжению.
- Повышение эффективности команд.

Пример наград:
| Уровень | Бонусы                                                                 |
|---------|------------------------------------------------------------------------|
| 1       | Базовые характеристики.                                                 |
| 5       | Доступ к команде "Поиск следов".                                        |
| 10      | Увеличение выносливости на 20%.                                         |
| 15      | Доступ к команде "Загон".                                               |

---

## **5. Система навыков**
### **5.1. Навыки преданности**
Лояльность собаки влияет на её поведение:
- Высокая лояльность: Собака выполняет команды быстрее и точнее.
- Низкая лояльность: Собака может игнорировать команды или выполнять их медленнее.

Лояльность повышается через:
- Кормление.
- Похвала.
- Совместное выполнение задач.

---

## **6. Управление собакой**
### **6.1. Команды собаке**
Игрок может отдавать собаке следующие команды:
- **Искать**: Поиск дичи в заданной области.
- **След**: Отслеживание следов животного.
- **Ко мне**: Возвращение собаки к игроку.
- **Сидеть**: Команда остановиться.
- **Лежать**: Команда замирания.

### **6.2. Иконки реакции собаки**
Иконки реагируют на состояние собаки:
- Зелёная иконка: Собака готова выполнять команды.
- Жёлтая иконка: Собака устала, но может продолжить работу.
- Красная иконка: Собака слишком устала и нуждается в отдыхе.

---

## **7. Ретривер**
### **7.1. Вариации**
- Золотистый ретривер.
- Лабрадор.

### **7.2. Кого может приносить**
Ретриверы специализируются на подносе дичи:
- Мелкие животные (утки, зайцы).
- Раненые крупные животные.

### **7.3. Навыки ретривера**
- Поднос дичи.
- Поиск раненых животных.
- Работа в воде.

### **7.4. Меню команд ретривера**
Меню содержит специфические команды для ретривера:
- "Подними добычу".
- "Поищи раненых".

---

## **8. Гончая**
### **8.1. Вариации**
- Английская гончая.
- Французская гончая.

### **8.2. Как выслеживать**
Гончие используют обоняние для отслеживания следов:
- Обнаружение свежих следов.
- Сообщение игроку о направлении движения дичи.

### **8.3. Навыки гончей**
- Отслеживание следов.
- Загон дичи.
- Работа в сложных условиях (лес, болота).

### **8.4. Меню команд гончей**
Меню содержит специфические команды для гончей:
- "Найди след".
- "Загони дичь".

---

## **9. Немецкий пойнтер**
### **9.1. Вариации**
- Короткошёрстный немецкий пойнтер.
- Длинношёрстный немецкий пойнтер.

### **9.2. Кого может выслеживать**
Немецкий пойнтер специализируется на выслеживании:
- Птиц (куропатки, фазаны).
- Мелких млекопитающих.

### **9.3. Навыки немецкого пойнтера**
- Указание места дичи.
- Тихое передвижение.
- Работа в открытой местности.

### **9.4. Меню команд немецкого пойнтера**
Меню содержит специфические команды для немецкого пойнтера:
- "Найди дичь".
- "Укажи место".

---

## **10. Другие факты о собаках**
- Собаки могут реагировать на внешние факторы (например, лай при виде хищников).
- Различные породы имеют уникальные звуки и анимации.

---

## **11. Снаряжение**
### **11.1. Ошейники**
- Увеличивают лояльность.
- Защищают шею от травм.

### **11.2. GPS маяк для собаки**
- Позволяет отслеживать местоположение собаки на карте.

### **11.3. Жилеты для собак**
- Защищают от холодов.
- Повышают выносливость.

### **11.4. Шейный платок для собак**
- Декоративный элемент.
- Может иметь бонусы к лояльности.

### **11.5. Использование собачьего снаряжения**
Снаряжение можно надевать через меню управления собакой.

---

## **12. Лакомства для собак**
Лакомства повышают лояльность и снижают усталость:
- Мясо.
- Специальные корма.

---

## **13. Рюкзаки для собак**
### **13.1. Варианты рюкзаков**
- Маленький рюкзак: 2 слота.
- Большой рюкзак: 5 слотов.

### **13.2. Использование рюкзаков для собак**
Рюкзаки позволяют собаке переносить дополнительные предметы.

---

## **14. Изображения ретривера**
![Ретривер](https://example.com/retriever.jpg)

---

## **15. Изображения гончей**
![Гончая](https://example.com/hound.jpg)  

16. Расширенная разработка механики
16.1. Создание класса собаки
Добавлены новые параметры: опыт (Experience), необходимый опыт для повышения уровня (RequiredExperienceForNextLevel) и специфические навыки для каждой породы.  

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

16.2. Реализация команд собаки
Расширены команды для каждой породы:  

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

16.3. Система лояльности и усталости
Добавлена проверка состояния собаки перед выполнением команд:  

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

16.4. Система опыта
Добавлена возможность повышения уровня через набор опыта:  

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

16.5. Управление несколькими собаками
Реализована возможность автоматического выбора наиболее подходящей собаки для выполнения команды:

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

16.6. Инвентарь и рюкзаки
Добавлена поддержка рюкзаков для собак:

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