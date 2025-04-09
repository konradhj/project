#pragma once
#include "AnimationWindow.h"
#include "widgets/Button.h"
#include <iostream>
#include "calculatorLogikk.h"

void createWindow();

TDT4102::Button addButton(const TDT4102::Point& buttonPosition, const std::string& buttonLabel);

int callback1();
int callback2();
int callback3();
int callback4();
int callback5();
int callback6();
int callback7();
int callback8();
int callback9();
int callback0();

void callbackEquals();
void callbackPlus();
void callbackMinus();
void callbackMultiply();
void callbackDivide();

void callbackC();
void callbackCE();
void callbackSign();
void callbackComma();
