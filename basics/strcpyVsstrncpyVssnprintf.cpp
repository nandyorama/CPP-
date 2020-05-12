#include <stdio.h> 
#include <string.h> 
int main() 
{ 
    char src[] = "geeksforgeeks"; 
      
    // Destination sting size which is less than length of src. 
    char dstrcpy[8]; 
    char dstrncpy[8];  
    char dsnprintf[8];  
    
    strcpy(dstrcpy, src); 
    int len = strlen(dstrcpy); 
    printf("Copied string: %s\n", dstrcpy); 
    printf("Length of destination string: %d\n", len); 
     
    strncpy(dstrncpy, src, 8); // dest is not NULL terminated implicitly.
    //dstrncpy[8]='\0';  //if not present then garbage is added.
    
    len = strlen(dstrncpy); // using strlen function on non terminated. string which can cause segfault. 
    printf("Copied string: %s\n", dstrncpy); 
    printf("Length of destination string: %d\n", len); 
    
      
    int j = snprintf(dsnprintf, 8, "%s\n", src); // dest is NULL terminated implicitly. so add extra +1 in length 
    len = strlen(dsnprintf); 
    printf("Copied string: %s\n", dsnprintf); 
    printf("Length of destination string: %d\n", len); 
   
    return 0; 
} 
