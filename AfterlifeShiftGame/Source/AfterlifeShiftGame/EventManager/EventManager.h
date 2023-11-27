#pragma once

#include "EventManager.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnLeftInput,float);
DECLARE_MULTICAST_DELEGATE(FOnRightInput);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UEventManager : public UActorComponent
{
GENERATED_BODY()
	
public:
	UEventManager();
	~UEventManager();
	
	static UEventManager* GetInstance();
	
	//UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Scale")
	FOnLeftInput OnAddWeightLeft;

	//UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Scale")
	FOnRightInput OnAddWeightRight;

private:
	static UEventManager* Instance;
};
