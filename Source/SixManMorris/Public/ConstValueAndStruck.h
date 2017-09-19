// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ConstValueAndStruck.generated.h"

/** Who's round? **/
UENUM(BlueprintType)
enum class EWhosRound : uint8
{
    None,
    First,
    Second,
    Referee,
};

/** Where am I? **/
UENUM(BlueprintType)
enum class EWhereAmI : uint8
{
    None,
    Checkerboard,
    OutOfCheckerboard,
};