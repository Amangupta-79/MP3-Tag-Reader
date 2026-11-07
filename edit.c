#include<stdio.h>
#include "header.h"
#include<string.h>
     
void edit_mp3(char *option, char *value, char *filename)
{
    FILE *fp = fopen(filename, "rb");  // original file

    if (fp == NULL)
    {
        printf("Cannot open sample.mp3\n");
        return;
    }

    FILE *new = fopen("temp.mp3", "wb");

    if (new == NULL)
    {
        printf("Cannot create temp.mp3\n");
        fclose(fp);
        return;
    }


 
    char tag[5];
    char *edit_name;
    char *field_name;

    if (strcmp(option, "-t") == 0)
    {
        strcpy(tag, "TIT2");
        edit_name = "CHANGE THE TITLE";
        field_name = "TITLE";
    }
    else if (strcmp(option, "-y") == 0)
    {
        strcpy(tag, "TYER");
        edit_name = "CHANGE THE YEAR";
        field_name = "YEAR";
    }
    else if (strcmp(option, "-A") == 0)
    {
        strcpy(tag, "TALB");
        edit_name = "CHANGE THE ALBUM";
        field_name = "ALBUM";
    }
    else if (strcmp(option, "-a") == 0)
    {
        strcpy(tag, "TPE1");
        edit_name = "CHANGE THE ARTIST";
        field_name = "ARTIST";
    }
    else if (strcmp(option, "-c") == 0)
    {
        strcpy(tag, "COMM");
        edit_name = "CHANGE THE COMMENT";
        field_name = "COMMENT";
    }
    else if (strcmp(option, "-i") == 0)
    {
        strcpy(tag, "TCON");
        edit_name = "CHANGE THE GENRE";
        field_name = "GENRE";
    }
    else
    {
        printf("Invalid editing option\n");
        fclose(fp);
        fclose(new);
        remove("temp.mp3");
        return;
    }

    // STEP 2: Display selected edit details

    printf("\n=====================================================\n");
    printf("!!!!!!!!!!!!!SELECTED EDIT DETAILS!!!!!!!!!!!!!\n");
    printf("=======================================================\n");

    printf("\n---------------- SELECTED EDIT OPTION ----------------\n");
    printf("\n---------------- %s ----------------\n", edit_name);

   unsigned char header[10];    // read the header

   fread(header, 1, 10, fp);
   fwrite(header, 1, 10, new);



   //tells you how many bytes of ID3 tag data follow the 10-byte header.
 int total_size = (header[6] << 21) |(header[7] << 14) | (header[8] << 7)|header[9];

   
 //read frame one by one

 int bytes_read = 0;
 char new_data[100];

 while(bytes_read < total_size)
 {
   char tag_name[5];

  if(fread(tag_name, 1, 4, fp)!=4)
      break;

  tag_name[4] = '\0';

 if (tag_name[0] == '\0')
 {
    fwrite(tag_name, 1, 4, new);


   unsigned char buffer[5000];

   int result;

while ((result = fread(buffer, 1, 5000, fp)) > 0)
{
    fwrite(buffer, 1, result, new);
   
    
}
    
  }

  unsigned char size[4];  // to reverse the four bytes

  fread(size, 1, 4,fp);


  int data_size = 0;

  char *ptr = (char *)&data_size;

  for (int i = 0; i < 4; i++)
  {
      ptr[i] = size[i];
  }

  for (int i = 0; i < 2; i++)
  {
    char temp = ptr[i];
    ptr[i] = ptr[3 - i];
    ptr[3 - i] = temp;
  }


// Copy the original 4 size bytes to temp.mp3
//read flags and frame data

 unsigned char flag[2];

 fread(flag, 1, 2, fp);

 unsigned char data[5000];            //variable to store the data.

  fread(data, 1, data_size, fp); 

  bytes_read =  bytes_read + 10 + data_size;






    if (strcmp(tag_name, tag) == 0)  // compare the frame name and edit
    {
        
         strcpy(new_data, value);
           
         int new_size = strlen(new_data) + 1;


        

        // Convert new size using the same swap method

        unsigned char size_bytes[4];
        
        char *p = (char *)&new_size;

        for (int i = 0; i < 4; i++)
            size_bytes[i] = p[i];

        for (int i = 0; i < 2; i++)
        {
            char temp = size_bytes[i];
            size_bytes[i] = size_bytes[3 - i];
            size_bytes[3 - i] = temp;
        }
  
        // write the updated frame data

        fwrite(tag_name, 1, 4, new);
        fwrite(size_bytes, 1, 4, new);
        fwrite(flag, 1, 2, new);
        fputc(0,new);
        fwrite(new_data, 1, new_size-1, new);
        break;
    }
     
    else
    {
        // Copy original frame unchanged

        fwrite(tag_name, 1, 4, new);
        fwrite(size, 1, 4, new);
        fwrite(flag, 1, 2, new);
        fwrite(data, 1, data_size, new);
    }

}


   unsigned char buffer[50000];

   int result;

while ((result = fread(buffer, 1, 50000, fp)) > 0)
{
    fwrite(buffer, 1, result, new);
   
    
}


    fclose(fp);
    fclose(new);



 if (remove(filename) == 0)
 {
    if (rename("temp.mp3", filename) == 0)
    {
        printf("\nMP3 file updated successfully!\n");
    }
 }

 printf("\n%-10s : %s\n", field_name, value);

printf("\n----------------%s CHANGED SUCCESSFULLY----------------\n",
       field_name); 


}


