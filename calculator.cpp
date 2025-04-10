#include "calculator.h"


void createWindow() {

    //Initialiserer posisjonen til vinduet
    int windowPositionX = 460;
    int windowPostitionY = 110;
    int windowWidth = 560;
    int windowHeight = 720;
    std::string windowTitle = "Kalkulator";
    TDT4102::AnimationWindow window(windowPositionX, windowPostitionY, windowWidth, windowHeight, windowTitle);

    //Legger til knapper
    TDT4102::Button button1 = addButton({0, 540}, "1");
    TDT4102::Button button2 = addButton({140, 540}, "2");
    TDT4102::Button button3 = addButton({280, 540}, "3");
    TDT4102::Button button4 = addButton({0, 450}, "4");
    TDT4102::Button button5 = addButton({140, 450}, "5");
    TDT4102::Button button6 = addButton({280, 450}, "6");
    TDT4102::Button button7 = addButton({0, 360}, "7");
    TDT4102::Button button8 = addButton({140, 360}, "8");
    TDT4102::Button button9 = addButton({280, 360}, "9");
    TDT4102::Button button0 = addButton({140, 630}, "0");

    TDT4102::Button buttonEquals = addButton({420, 630}, "=");
    TDT4102::Button buttonPlus = addButton({420, 540}, "+");
    TDT4102::Button buttonMinus = addButton({420, 450}, "-");
    TDT4102::Button buttonMultiply = addButton({420, 360}, "×");
    TDT4102::Button buttonDivide = addButton({420, 270}, "÷");

    TDT4102::Button buttonC = addButton({0, 270}, "C");
    TDT4102::Button buttonCE = addButton({140, 270}, "CE");
    TDT4102::Button buttonSign = addButton({280, 270}, "+/-");
    TDT4102::Button buttonComma = addButton({280, 630}, ",");
    TDT4102::Button buttonNothing = addButton({0, 630}, "");

    //initialiserer knappene med callbackfunksjon og legger dem til i vinduet

    //Tall
    window.add(button1);
    button1.setCallback(callback1);

    window.add(button2);
    button2.setCallback(callback2);

    window.add(button3);
    button3.setCallback(callback3);

    window.add(button4);
    button4.setCallback(callback4);

    window.add(button5);
    button5.setCallback(callback5);

    window.add(button6);
    button6.setCallback(callback6);

    window.add(button7);
    button7.setCallback(callback7);

    window.add(button8);
    button8.setCallback(callback8);

    window.add(button9);
    button9.setCallback(callback9); 

    window.add(button0);
    button0.setCallback(callback0);

    //Operasjoner
    window.add(buttonEquals);
    buttonEquals.setCallback(callbackEquals);

    window.add(buttonPlus);
    buttonPlus.setCallback(callbackPlus);

    window.add(buttonMinus);
    buttonMinus.setCallback(callbackMinus);

    window.add(buttonMultiply);
    buttonMultiply.setCallback(callbackMultiply);

    window.add(buttonDivide);
    buttonDivide.setCallback(callbackDivide);

    //Diverse
    window.add(buttonC);
    buttonC.setCallback(callbackC);

    window.add(buttonCE);
    buttonCE.setCallback(callbackCE);

    window.add(buttonSign);
    buttonSign.setCallback(callbackSign);

    window.add(buttonComma);
    buttonComma.setCallback(callbackComma);

    window.add(buttonNothing);

    while (!window.should_close()) {

        //Lager rektangel for det visuelle
        TDT4102::Point rectanglePt {0, 100};
        TDT4102::Color rectangleColor = TDT4102::Color::gray;
        int rectangleWidth = 560;
        int rectangleHeight = 150;
        window.draw_rectangle(rectanglePt, rectangleWidth, rectangleHeight, rectangleColor);
        
        //Skriver output på vinduet
        TDT4102::Point location {10, 110};
        TDT4102::Color textColor = TDT4102::Color::white;
        int fontSize = 120;
        window.draw_text(location, "Test", textColor, fontSize);

        window.next_frame();
    }

}

TDT4102::Button addButton(const TDT4102::Point& buttonPosition, const std::string& buttonLabel) {
    const unsigned int buttonWidth = 140;
    const unsigned int buttonHeight = 90;
    TDT4102::Button button {buttonPosition, buttonWidth, buttonHeight, buttonLabel};

    return button;
}

void textOutput(std::string output) {
    
}