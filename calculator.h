#pragma once
#include "AnimationWindow.h"
#include "widgets/Button.h"
#include <iostream>
#include "calculatorLogikk.h"
#include "callback.h"

void createWindow();

TDT4102::Button addButton(const TDT4102::Point& buttonPosition, const std::string& buttonLabel);