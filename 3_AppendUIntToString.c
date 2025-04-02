#define NULL '\0'

void UIntToHexStr(unsigned int uiValue, char pcStr[])
{
   unsigned char ucNibbleCounter;
   unsigned char ucCurrentNibble;

   pcStr[0] = '0';
   pcStr[1] = 'x';
   pcStr[6] = NULL;
// git test	
   for(ucNibbleCounter = 0; ucNibbleCounter < 4; ucNibbleCounter++)
   {
      ucCurrentNibble = (uiValue >> (ucNibbleCounter * 4)) & 0x0F;
      if(ucCurrentNibble<10)
      {
          pcStr[5 - ucNibbleCounter] = '0' + ucCurrentNibble;
      }
      else
      {
         pcStr[5 - ucNibbleCounter] = 'A' + (ucCurrentNibble - 10);
      }
   }
}

void AppendUIntToString(unsigned int uiValue, char pcDestinationStr[])
{
    unsigned char ucArrayEndCounter;

    for(ucArrayEndCounter = 0; pcDestinationStr[ucArrayEndCounter] != NULL; ucArrayEndCounter++){}
    UIntToHexStr(uiValue, &pcDestinationStr[ucArrayEndCounter]);
}

unsigned int uiValue = 65000;
char pcDestinationStr[10] = "abc";

int main(){
	AppendUIntToString(uiValue, pcDestinationStr);
}
