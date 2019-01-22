// Fill out your copyright notice in the Description page of Project Settings.

#include "NPCCharacter_C.h"
#include "Engine/GameEngine.h"
#include "ConstructorHelpers.h"
#include "GameFramework/Controller.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardData.h"

FName ANPCCharacter_C::BlackboardKeys[] = {TEXT("ListBehaviour"), TEXT("WaitTime"), TEXT("TargetListIndex"), TEXT("CurrentTarget"), TEXT("CanNoticePlayer")};

// Sets default values
ANPCCharacter_C::ANPCCharacter_C()
  : WaitTime(0.0f)
  , ShouldNoticePlayer(false)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

  NPC_Sight = CreateDefaultSubobject<UAIPerceptionComponent>("NPC_Sight");

  //ConstructorHelpers::FObjectFinder<UBlackboardData> blackboard(TEXT("BlackboardData'/Game/WheelieChairContent/NPCCharacter/AI/NPCAI_Blackboard.NPCAI_Blackboard'"));
}

// Called when the game starts or when spawned
void ANPCCharacter_C::BeginPlay() {
	Super::BeginPlay();

    AAIController* ownAI = Cast<AAIController>(ANPCCharacter_C::GetController());
    
    if (ownAI != nullptr) {

      //ConstructorHelpers::FObjectFinder<UBlackboardData> blackboard(TEXT("BlackboardData'/Game/WheelieChairContent/NPCCharacter/AI/NPCAI_Blackboard.NPCAI_Blackboard'"));
      //ownAI->UseBlackboard();

      if (GEngine) {
        //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, blackboard.Object->GetFullName());
      }
    }
}

// Called every frame
void ANPCCharacter_C::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ANPCCharacter_C::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

