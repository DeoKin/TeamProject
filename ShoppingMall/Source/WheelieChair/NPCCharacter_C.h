// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Perception/AIPerceptionComponent.h"
#include "NPCCharacter_C.generated.h"

UENUM(BlueprintType)
enum class ENPCBehaviour : uint8 {
  VE_Nothing UMETA(DisplayName = "Do Nothing"),
  VE_Random UMETA(DisplayName = "At Random"),
  VE_OrderLoop UMETA(DisplayName = "In Order - One Way"),
  VE_OrderPingPong UMETA(DisplayName = "In Order - Two Way"),
  VE_Follow UMETA(DisplayName = "Follow")
};

/**
* DON'T USE THIS CLASS, IT DIDN'T WORK OUT
*
* This class represents to regular NPCs that will inhabit the level(s) in this game.
* They can have various behaviours (e.g. travel between points at random, follow an Game Actor), as determined by the user
*/
UCLASS()
class WHEELIECHAIR_API ANPCCharacter_C : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPCCharacter_C();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    UAIPerceptionComponent* NPC_Sight;

    /** Determines the actions this NPC will partake in. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    ENPCBehaviour Behaviour;

    /** The list of actors this NPC will travel to.
    *
    * If Behaviour is 'Follow', only the first entry in the list will get used.
    * Any Actor can be used for the NPC to follow.
    *
    * Otherwise, the whole list will be used.
    * Using TargetPoints only is recommended in that case.
    */
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TArray<AActor*> TargetList;

    /** How long must the NPC wait until they pick another point to travel to?
    * (Not applicable if Behaviour is set to 'Follow')
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0.0"))
    float WaitTime;

    /** Will this NPC be allowed to 'notice' the player?
    * If set to 'True', they will stop any action they are performing, once the player comes close enough, and rotate to face the player.
    * They will return to their regular actions when the player leaves their sights.
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool ShouldNoticePlayer;

private:
  //The blackboard keys this NPC's AI Controller will use in its behaviour tree
  //Static because they're the same across all instances
  static FName BlackboardKeys[];
};
