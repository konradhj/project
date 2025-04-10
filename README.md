Plan for prosjekt:

Kalkulator

Dokumentasjon:

globals.h & globals.cpp:
- I disse filene defineres variabler som blir brukt globalt mellom alle filene våre. Dette er mest for å lage en god oversikt over
de globale variablene, slik at de ikke ligger over alt.
- std::string message er variablen som holder meldingen som sendes ut til skjerm.
- std::string siffer er en midlertidig tall-holder.
- std::vector tall blir brukt for å regne ut det endelige tallet.
- std::vector operasjon lagrer operasjonene som blir trykket på.

callback.h & callback.cpp:
- Disse filene er brukt for ryddighetens skyld og inneholder callback funksjonene til knappene som blir laget.
- Alle knappene på kalkulatoren (utenom den tomme knappen) har en callback-funksjon for å aktivere andre funksjoner og operasjoner
når den respektive knappen er trykket på.

calculator.h & calculator.cpp:
- Dette er hovedfilen for koden til GUI til kalkulatoren. Her finnes funksjonene som gjør at kalkulatoren ser ut som den gjør.
- "Hjelpefunksjonen" addButton() er en generalisert funksjon som legger til en knapp i GUI. Den tar inn posisjon og hva det 
skal stå på knappen.
- Hovedfunksjonen i filen er createWindow(). Det er også denne som kjøres av main.cpp for å kjøre hele programmet.
- createWindow() lager selve vinduet og bestemmer hvor stort dette skal være og hvor det skal være på skjermen. Videre lager den
alle knappene den trenger ved hjelp av addButton() og setter opp callbackfunksjoner til hver enkelt knapp. Det siste i funksjonen
er selve while-løkken der teksten blir oppdatert mens vinduet er oppe. Formen på teksten blir definert av koden inne i while-løkken
og selve teksten bestemmes ut ifra den globale variabelen "message" som endres i logikken beskrevet under.

calculatorLogikk.h & calculatorLogikk.cpp:
- Dette er filen som definerer alt som  har med logikk bak kalkulatoren. Denne bestemmer hva som vises på skjerm basert på
hva brukeren trykker inn.
- output() oppdaterer den lokale variabelen nuOutput og skriver ut meldingen til terminalen. Dette er i all hovedsak brukt for
debugging.
- operasjonstrykk() håndterer hva som skjer når brukeren trykker på en operasjonsknapp. Den tar for seg to tilfeller:
    1. Dersom man allerede har skrevet inn et tall (lagret i siffer variabelen)
        - Da lagrer den operatoren og tallet, tømmer siffer igjen slik at den kan brukes på nytt og viser operatoren til skjerm.
    2. Dersom man trykker på en ny operator
        - Da oppdaterer den operatoren fra den gamle til den nye og endrer message variabelen henholdsvis.
- lagTall() lagrer sifferet som brukeren trykker på.
- clear() tilbakestiller kalkulatoren. Tømmer alle globale variabler.
- clearEntry() fjerner siste siffer som ble lagt inn.
- euqals() er hovedfunksjonen bak logikken og håndterer det som skjer etter man trykker på likhetstegnet. Den prøver å lagre siste
tall dersom noe er skrevet inn i siffer variabelen. Deretter sjekker den om det ikke er noe tall eller det er for mange operatorer
Så håndterer den * og / før + og -. Til slutt lagrer den resultatet i message.

main.cpp:
- Kjører koden.
