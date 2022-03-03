#include "enigma.h"

const char *ROTOR_CONSTANTS[] = {
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ", // Identity Rotor (index 0 - and useful for testing):
        "EKMFLGDQVZNTOWYHXUSPAIBRCJ",
        "AJDKSIRUXBLHWTMCQGZNPYFVOE",
        "BDFHJLCPRTXVZNYEIWGAKMUSQO",
        "ESOVPZJAYQUIRHXLNFTGKDCMWB",
        "VZBRGITYUPSDNHLXAWMJQOFECK",
        "JPGVOUMFYQBENHZRDKASXLICTW",
        "NZJHGRCXMYSWBOUFAIVLPEKQDT",
        "FKQHTLXOCBJSPDZRAMEWNIUYGV",
};


/*
 *
 * ZACHARY COLLINS (ztcollins@wisc.edu)

ENCRYPTION:

JAVA
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"FKQHTLXOCBJSPDZRAMEWNIUYGV" 8
BFIF

BFIF
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"AJDKSIRUXBLHWTMCQGZNPYFVOE" 2
JIXI


DECRYPTION:

JIXI
"AJDKSIRUXBLHWTMCQGZNPYFVOE"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
BFIF

BFIF
"FKQHTLXOCBJSPDZRAMEWNIUYGV"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
JAVA


ROTATIONS:

"EKMFLGDQVZNTOWYHXUSPAIBRCJ"
"RCJEKMFLGDQVZNTOWYHXUSPAIB" <-- rotated by 3

*/


// This method reads a character string from the keyboard and 
// stores the string in the parameter msg.
// Keyboard input will be entirely uppercase and spaces followed by 
// the enter key.  
// The string msg should contain only uppercase letters spaces and 
// terminated by the '\0' character
// Do not include the \n entered from the keyboard
void Get_Message(char msg[]){
    
    scanf("%[^\n]", msg);

    return;
}

// This function reads up to 4 characters from the keyboard
// These characters will be only digits 1 through 8. The user
// will press enter when finished entering the digits.
// The rotor string filled in by the function should only contain 
// the digits terminated by the '\0' character. Do not include
// the \n entered by the user. 
// The function returns the number of active rotors.
int Get_Which_Rotors(char which_rotors[]){
	
    scanf("%4s", which_rotors);


    int count = 0;

    if(which_rotors[0] > 47 && which_rotors[0] < 58) {
	count++;
    }

    if(which_rotors[1] > 47 && which_rotors[1] < 58) {
        count++;
    }

    if(which_rotors[2] > 47 && which_rotors[2] < 58) {
        count++;
    }

    if(which_rotors[3] > 47 && which_rotors[3] < 58) {
        count++;
    }

    return count;
} 

// This function reads an integer from the keyboard and returns it 
// This number represents the number of rotations to apply to the 
// encryption rotors.  The input will be between 0 and 25 inclusive
int Get_Rotations(){

    int rotations = 0;
	
    scanf("%d", &rotations);

    return rotations;
}


// This function copies the rotors indicated in the which_rotors string 
// into the encryption_rotors.  For example if which rotors contains the string 
// {'3', '1', '\0'} Then this function copies the third and first rotors into the 
// encryption rotors array in positions 0 and 1.  
// encryptions_rotors[0] = "BDFHJLCPRTXVZNYEIWGAKMUSQO"
// encryptions_rotors[1] = "EKMFLGDQVZNTOWYHXUSPAIBRCJ"
void Set_Up_Rotors(char encryption_rotors[4][27], char which_rotors[5]){
	
    int rotor = 0;

    for(int i = 0; i < 4; i++) {
	    if(which_rotors[i] > 47 && which_rotors[i] < 58) {
		    rotor = which_rotors[i]-48;
		    strcpy(encryption_rotors[i], ROTOR_CONSTANTS[rotor]);

		    //encryption_rotors[i] = ROTOR_CONSTANTS[rotor];
		    //for(int *pa = arr; pa != &arr[5]; pa++)
            }
    }


    	return;
}


// This function rotates the characters in each of the active encryption rotors
// to the right by rotations.  For example if rotations is 3 encryption_rotors[0]
// contains "BDFHJLCPRTXVZNYEIWGAKMUSQO" then after rotation this row will contain
// SQOBDFHJLCPRTXVZNYEIWGAKMU.  Apply the same rotation to all for strings in 
// encryption_rotors
void Apply_Rotation(int rotations, char encryption_rotors[4][27]) {

    for(int i = 0; i < 4; i++) {

	    for(int a = 0; a < rotations; a++) {
	        char previousChar;
		char currentChar;
		for(int j = 0; j < 26; j++) {

		    if(j == 0) {
			previousChar = encryption_rotors[i][j];
			encryption_rotors[i][j] = encryption_rotors[i][25];
		    }
			//elseif(j == 26) {
				
			//}
		    else {
			    currentChar = encryption_rotors[i][j]; // STORE CURRENT LETTER
			    encryption_rotors[i][j] = previousChar; // SET CURRENT TO PREVIOUS TEMP
			    previousChar = currentChar; // SET PREVIOUS TEMP TO CURRENT
	    	    }
   	 }
    }
    }

    return;
}

// This function takes a string msg and applys the enigma machine to encrypt the message
// The encrypted message is stored in the string encryped_msg 
// Do not change spaces, make sure your encryped_msg is a \0 terminated string
void Encrypt(char encryption_rotors[4][27], int num_active_rotors, char msg[], char encrypted_msg[]){
    

    strcpy(encrypted_msg, msg);	
	//printf("%s\n", encryption_rotors[0]);
	//printf("%s\n", encryption_rotors[1]);
	/*
	for(int j = 0; msg[j] != '\0'; j++) {
        	if(encrypted_msg[j] != ' ') {
                   	//printf("%s\n", decrypted_msg);
                        encrypted_msg[j] = encryption_rotors[0][(encrypted_msg[j]-65)];
              	}
        }*/

    for(int i = 0; i < num_active_rotors; i++) {
	    for(int j = 0; msg[j] != '\0'; j++) {
		    if(msg[j] != ' ') {
			    //printf("%s\n", encrypted_msg);
			    char charToFind = encrypted_msg[j];
			    //char *ptr = strchr(encryption_rotors[i], charToFind);}
			    int index = (int)(strchr(ROTOR_CONSTANTS[0], charToFind)-ROTOR_CONSTANTS[0]);
			    //printf("%d\n", index);
			    encrypted_msg[j] = encryption_rotors[i][index];
		    }
	    }
    }

    return;
}


// This function takes a string msg and applys the enigma machine to decrypt the message
// The encrypted message is stored in the string encryped_msg and the decrypted_message 
// is returned as a call by reference variable
// remember the encryption rotors must be used in the reverse order to decrypt a message
// Do not change spaces, make sure your decrytped_msg is a \0 terminated string
void Decrypt(char encryption_rotors[4][27], int num_active_rotors, char encrypted_msg[], char decrypted_msg[]) {
   	
	//printf("%s DECRYPT??? \n", encrypted_msg);
        strcpy(decrypted_msg, encrypted_msg);
	//printf("%s DECRYPT??? \n", decrypted_msg);	
	//decrypted_msg = encrypted_msg;
	/*
        for(int i = num_active_rotors; i > -1; i--) {
                for(int j = 0; encrypted_msg[j] != '\0'; j++) {
			if(encrypted_msg[j] != ' ') {
				printf("%s\n", decrypted_msg);
                        	decrypted_msg[j] = encryption_rotors[i][(encrypted_msg[j]-65)];
			}
                }
        }*/

	//encrypted_msg = "NCLJMABF XNZBTNB";

	char rotor0[27];

	strcpy(rotor0, ROTOR_CONSTANTS[0]);

	for(int i = num_active_rotors-1; i > -1; i--) {
                for(int j = 0; decrypted_msg[j] != '\0'; j++) {
                        if(decrypted_msg[j] != ' ') {
                                //printf("%s DECRYPT \n", decrypted_msg);
                                char charToFind = decrypted_msg[j];
                                //char *ptr = strchr(encryption_rotors[i], charToFind);}
                                int index = (int)(strchr(encryption_rotors[i], charToFind)-encryption_rotors[i]);
                                //printf("%d\n", index);
                                decrypted_msg[j] = rotor0[index];
                        }
                }
        }

	
	return;
}

