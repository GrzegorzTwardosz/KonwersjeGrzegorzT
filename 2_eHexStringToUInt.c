#define NULL '\0'
enum Result {OK, ERROR};
enum Result eHexStringToUIntResult;

enum Result eHexStringToUInt(char pcStr[],unsigned int *puiValue)
{
    unsigned char ucCharacterCounter;
    unsigned char ucCurrentCharacter;

    *puiValue = 0;
    if((pcStr[0] != '0') || (pcStr[1] != 'x') || (pcStr[2] == NULL))
    {
        return ERROR;
    }
    for(ucCharacterCounter = 2; pcStr[ucCharacterCounter] !=NULL ; ucCharacterCounter++)
    {
        ucCurrentCharacter = pcStr[ucCharacterCounter];
        if (ucCharacterCounter == 6)
        {
            return ERROR;
        }
	  *puiValue = *puiValue << 4;
        if((ucCurrentCharacter <= '9') && (ucCurrentCharacter >= '0'))
        {
            *puiValue = (*puiValue) | (ucCurrentCharacter - '0');
        }
        else if((ucCurrentCharacter <= 'F') && (ucCurrentCharacter >= 'A'))
        {
            *puiValue = (*puiValue) | (ucCurrentCharacter - 'A' + 10);
        }
        else
        {
            return ERROR;
        }
    }
    return OK;
}

char pcStr[] = "0xABC";
unsigned int uiValue;

int main(){
	eHexStringToUIntResult = eHexStringToUInt(pcStr, &uiValue);
}
