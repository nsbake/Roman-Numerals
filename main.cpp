#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int value(char romanNumeral) //Returns the value of a single roman numeral
{
    if(romanNumeral == 'I')
    {
        return 1;
    }
    if(romanNumeral == 'V')
    {
        return 5;
    }
    if(romanNumeral == 'X')
    {
        return 10;
    }
    if(romanNumeral == 'L')
    {
        return 50;
    }
    if(romanNumeral == 'C')
    {
        return 100;
    }
    if(romanNumeral == 'D')
    {
        return 500;
    }
    if(romanNumeral == 'M')
    {
        return 1000;
    }
    
    return 0;
}

void translateRomanNumeral(string romanNumeral) // Translates roman numeral into it's numeric value
{
    int numericTotal = 0;
    
    for(int i = 0; i < romanNumeral.size(); i++)
    {
        if(i != romanNumeral.size() - 1) // Avoids out of bounds error by checking if we are on the last character and if we are skipping the + 1 check
        {
            if(value(romanNumeral.at(i)) < value(romanNumeral.at(i + 1))) // If the roman numeral at the current position is less than the one following it, does subtract notation then adds it to numericTotal
            {
                numericTotal += value(romanNumeral.at(i + 1)) - value(romanNumeral.at(i));
                i++;
            }
            else // Otherwise just add it to numericTotal
            {
                numericTotal += value(romanNumeral.at(i));
            }
        }
        else
        {
            numericTotal += value(romanNumeral.at(i));
        }
    }
    
    cout << "Roman Numeral equals: " << numericTotal << endl;
}

void translateNumber(int userNumber) // Translates numbers into roman numerals
{
    string romanNumeral = "";
    
    /* Each if statement calculates how many of each roman numeral should be placed for
       the inputted user number. It then types out that many of that roman numeral, alters
       the user number to continue to the next calculation and repeats the process for
       each roman numeral.*/
    
    if(userNumber >= value('M'))
    {
        for(int i = 0; i < userNumber / value('M'); i++)
        {
            romanNumeral += "M";
        }
        userNumber -= (userNumber/value('M')) * value('M');
    }
    if(userNumber >= value('D'))
    {
        if(userNumber >= value('M') - value('C'))
        {
            romanNumeral += "CM";
            userNumber -= value('M') - value('C');
        }
        else
        {
            romanNumeral += "D";
            userNumber -= value('D');
        }
    }
    if(userNumber >= value('C'))
    {
        if(userNumber >= value('D') - value('C'))
        {
            romanNumeral += "CD";
            userNumber -= value('D') - value('C');
        }
        else
        {
            for(int i = 0; i < userNumber / value('C'); i++)
            {
                romanNumeral += "C";
            }
            userNumber -= (userNumber/value('C')) * value('C');
        }
    }
    if(userNumber >= value('L'))
    {
        if(userNumber >= value('C') - value('X'))
        {
            romanNumeral += "XC";
            userNumber -= value('C') - value('X');
        }
        else
        {
            romanNumeral += "L";
            userNumber -= value('L');
        }
    }
    if(userNumber >= value('X'))
    {
        if(userNumber >= value('L') - value('X'))
        {
            romanNumeral += "XL";
            userNumber -= value('L') - value('X');
        }
        else
        {
            for(int i = 0; i < userNumber / value('X'); i++)
            {
                romanNumeral += "X";
            }
            userNumber -= (userNumber/value('X')) * value('X');
        }
    }
    if(userNumber >= value('V'))
    {
        if(userNumber >= value('X') - value('I'))
        {
            romanNumeral += "IX";
            userNumber -= value('X') - value('I');
        }
        else
        {
            romanNumeral += "V";
            userNumber -= value('V');
        }
    }
    if(userNumber >= value('I'))
    {
        if(userNumber == value('V') - value('I'))
        {
            romanNumeral += "IV";
            userNumber -= value('V') - value('I');
        }
        else
        {
            for(int i = 0; i < userNumber / value('I'); i++)
            {
                romanNumeral += "I";
            }
            userNumber -= (userNumber/value('I')) * value('I');
        }
    }
    
    cout << "Roman numeral translated to: " << romanNumeral << endl;
}

int main(int argc, const char * argv[])
{
    string romanNumeral;
    int userNumber;

    
    while(romanNumeral != "STOP") // Loop that allows user to translate as many roman numerals to numbers as desired
    {
        cout << "Please enter a roman numeral (Type STOP to move on): ";
        cin >> romanNumeral;
        if(romanNumeral == "STOP")
        {
            break;
        }
        else
        {
            translateRomanNumeral(romanNumeral);
        }
    }
    
    
    
    do // Loop that allows user to translate as many numbers to roman numerals as desired
    {
        cout << "Please enter a number (Type 0 to end): ";
        cin >> userNumber;
        if(userNumber == 0)
        {
            break;
        }
        else
        {
            translateNumber(userNumber);
        }
    }while(userNumber != 0);
    
    
    return 0;
}
