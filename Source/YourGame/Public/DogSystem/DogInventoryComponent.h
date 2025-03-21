#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DogInventoryComponent.generated.h"

/**
 * Структура для предмета в инвентаре собаки
 */
USTRUCT(BlueprintType)
struct FDogInventoryItem
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    FString ItemName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    UTexture2D* ItemIcon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    float Weight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    TSubclassOf<AActor> ItemClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    AActor* ItemActor;

    FDogInventoryItem()
        : ItemName(TEXT(""))
        , ItemIcon(nullptr)
        , Weight(0.0f)
        , ItemClass(nullptr)
        , ItemActor(nullptr)
    {
    }
};

/**
 * Компонент инвентаря для собаки
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class YOURGAME_API UDogInventoryComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UDogInventoryComponent();

    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    /**
     * Добавить предмет в инвентарь
     * @param Item Предмет для добавления
     * @return True, если предмет успешно добавлен
     */
    UFUNCTION(BlueprintCallable, Category = "Dog Inventory")
    bool AddItem(const FDogInventoryItem& Item);

    /**
     * Удалить предмет из инвентаря
     * @param Index Индекс предмета для удаления
     * @return True, если предмет успешно удален
     */
    UFUNCTION(BlueprintCallable, Category = "Dog Inventory")
    bool RemoveItem(int32 Index);

    /**
     * Получить предмет из инвентаря
     * @param Index Индекс предмета
     * @param OutItem Полученный предмет
     * @return True, если предмет успешно получен
     */
    UFUNCTION(BlueprintCallable, Category = "Dog Inventory")
    bool GetItem(int32 Index, FDogInventoryItem& OutItem) const;

    /**
     * Получить все предметы в инвентаре
     * @return Массив предметов
     */
    UFUNCTION(BlueprintCallable, Category = "Dog Inventory")
    TArray<FDogInventoryItem> GetAllItems() const;

    /**
     * Получить текущий вес инвентаря
     * @return Текущий вес
     */
    UFUNCTION(BlueprintCallable, Category = "Dog Inventory")
    float GetCurrentWeight() const;

    /**
     * Получить максимальный вес инвентаря
     * @return Максимальный вес
     */
    UFUNCTION(BlueprintCallable, Category = "Dog Inventory")
    float GetMaxWeight() const;

    /**
     * Установить максимальный вес инвентаря
     * @param NewMaxWeight Новый максимальный вес
     */
    UFUNCTION(BlueprintCallable, Category = "Dog Inventory")
    void SetMaxWeight(float NewMaxWeight);

    /**
     * Проверить, может ли инвентарь вместить предмет
     * @param ItemWeight Вес предмета
     * @return True, если инвентарь может вместить предмет
     */
    UFUNCTION(BlueprintCallable, Category = "Dog Inventory")
    bool CanAddItem(float ItemWeight) const;

    /**
     * Получить количество предметов в инвентаре
     * @return Количество предметов
     */
    UFUNCTION(BlueprintCallable, Category = "Dog Inventory")
    int32 GetItemCount() const;

    /**
     * Очистить инвентарь
     */
    UFUNCTION(BlueprintCallable, Category = "Dog Inventory")
    void ClearInventory();

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog Inventory")
    TArray<FDogInventoryItem> Items;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog Inventory")
    float MaxWeight;

private:
    float CalculateCurrentWeight() const;
};
