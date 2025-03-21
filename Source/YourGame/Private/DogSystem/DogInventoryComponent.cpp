#include "DogSystem/DogInventoryComponent.h"

UDogInventoryComponent::UDogInventoryComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    MaxWeight = 10.0f; // Стандартный максимальный вес - 10 кг
}

void UDogInventoryComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UDogInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

bool UDogInventoryComponent::AddItem(const FDogInventoryItem& Item)
{
    if (!CanAddItem(Item.Weight))
    {
        return false;
    }

    Items.Add(Item);
    return true;
}

bool UDogInventoryComponent::RemoveItem(int32 Index)
{
    if (!Items.IsValidIndex(Index))
    {
        return false;
    }

    Items.RemoveAt(Index);
    return true;
}

bool UDogInventoryComponent::GetItem(int32 Index, FDogInventoryItem& OutItem) const
{
    if (!Items.IsValidIndex(Index))
    {
        return false;
    }

    OutItem = Items[Index];
    return true;
}

TArray<FDogInventoryItem> UDogInventoryComponent::GetAllItems() const
{
    return Items;
}

float UDogInventoryComponent::GetCurrentWeight() const
{
    return CalculateCurrentWeight();
}

float UDogInventoryComponent::GetMaxWeight() const
{
    return MaxWeight;
}

void UDogInventoryComponent::SetMaxWeight(float NewMaxWeight)
{
    MaxWeight = FMath::Max(0.0f, NewMaxWeight);
}

bool UDogInventoryComponent::CanAddItem(float ItemWeight) const
{
    return (GetCurrentWeight() + ItemWeight) <= MaxWeight;
}

int32 UDogInventoryComponent::GetItemCount() const
{
    return Items.Num();
}

void UDogInventoryComponent::ClearInventory()
{
    Items.Empty();
}

float UDogInventoryComponent::CalculateCurrentWeight() const
{
    float TotalWeight = 0.0f;
    for (const FDogInventoryItem& Item : Items)
    {
        TotalWeight += Item.Weight;
    }
    return TotalWeight;
}
