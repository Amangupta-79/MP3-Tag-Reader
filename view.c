#include<stdio.h>
#include "header.h"
#include<string.h>



void view_mp3(char *filename)


{
   

    int count=0;                       // count is for stop the while loop.



   FILE *fp= fopen(filename, "rb");

      if(fp == NULL)                   //check file is present or not.
      {
        printf("File not found\n");
        return;
      }
       
  


   printf(BOLD_CYAN"\n====================================================\n"RESET);
   printf(BOLD_CYAN"                 MP3 TAG READER\n"RESET);
   printf(BOLD_CYAN"====================================================\n"RESET);

   printf(BOLD_YELLOW"\n                 MP3 FILE DETAILS\n\n"RESET);
   printf(CYAN"----------------------------------------------------\n"RESET);



    fseek(fp, 10, SEEK_SET);            // skip 10 bytes of header details.


  while(count <6)
  {

  char tag_name[5];                    //variable for tag name.

  fread(tag_name, 1, 4, fp);           //read  tag size eg title--> TIT2 read only 4 bytes data.
                             

  tag_name[4] = '\0';                  //after reading 4 bytes than put '\0'.to stop.

  printf("\n");

  unsigned char size[4];             // variable for store frame size.
         

 fread(size, 1, 4, fp);        // read size bytes (4) of frame.
          


// convert big to littile endian size from swaping.

 int data_size = 0;

 char*ptr=(char*)&data_size;
 
 for (int i = 0; i<4; i++)
 {
      ptr[i] =size[i];
 }

 for(int i=0; i<2; i++)
  {
      char temp = ptr[i];
      ptr[i] = ptr[4-i-1];
      ptr[4-i-1] = temp;
  }

  fseek(fp, 2, SEEK_CUR);             // it skips flag bytes and null total 3 bytes.

  unsigned char data[100];            //variable to store the data.

fread(data, 1, data_size, fp); 
 //read data from file and store in data.

 

  if(strcmp (tag_name, "TIT2") == 0)        // comparing tag like TIT2 is present for title.
   {
        printf(BOLD_YELLOW"Title     : "RESET GREEN);

      for (int i = 1; i<data_size; i++)    // printing data of title
      {
            if(data[i]=='\0')
             break;

           printf("%c", data[i]);
      }
       
         printf(RESET"\n");
         count++;                          // increasing count if found.
    }


  if(strcmp (tag_name, "TYER") == 0)       // comparing tag like TYER is present for Year.
   {
        printf(BOLD_YELLOW"YEAR      : "RESET GREEN);

      for (int i = 1; i <data_size; i++)      // printing data of title.
      {
             if(data[i]=='\0')
             break;

           printf("%c", data[i]);
      }
        
        printf(RESET"\n");
        count++;
    }


  if(strcmp (tag_name, "TPE1") == 0)    // comparing tag like TPE1 is present for Year.
   {
       printf(BOLD_YELLOW"Artist    : "RESET GREEN);

     for (int i = 1; i < data_size; i++)    // printing data of title
      {
            if(data[i]=='\0')
             break;

           printf("%c", data[i]);
      }
        
        printf(RESET"\n");
        count++;
    }

  if(strcmp (tag_name, "TALB") == 0)
   {
        printf(BOLD_YELLOW"Album     : "RESET GREEN);

     for (int i = 1; i < data_size; i++)
      {
             if(data[i]=='\0')
             break;

           printf("%c", data[i]);
        }
        
        printf(RESET"\n");
        count++;
    }

  if(strcmp (tag_name, "TCON") == 0)
   {
         printf(BOLD_YELLOW"Genre     : "RESET GREEN);

      for (int i = 1; i<data_size; i++)
      {
             if(data[i]=='\0')
             break;

           printf("%c", data[i]);
      }
        printf(RESET"\n");
        count++;
    }

  if(strcmp (tag_name, "COMM") == 0)
   {
        printf(BOLD_YELLOW"Comment   : "RESET GREEN);

    for (int i = 1; i < data_size; i++)
     {
             if(data[i]=='\0')
             break;

           printf("%c", data[i]);
     }
      
        printf(RESET"\n");
        count++;
    }


 

}

printf(CYAN"----------------------------------------------------\n"RESET);
printf(BOLD_GREEN"\n       MP3 DETAILS DISPLAYED SUCCESSFULLY!\n"RESET);
printf(BOLD_CYAN"\n====================================================\n"RESET);
 
     fclose(fp);

}

