
#include <stdio.h>
#include "header.h"
#include<string.h>

int main(int argc,char*argv[])
{
   // checking the command line arguments is less then 2 then print this messages.

    if(argc<2)
    {
        printf("-------------------------------------------------------\n");
        printf(RED BOLD"\nError : %s: Invalid Arguments\n"RESET,argv[0]);
        
        printf(YELLOW BOLD"\n---------!!! Usages Message !!!--------\n"RESET);
        printf(CYAN"\nTo view file pass like this : %s -v mp3filename\n"RESET,argv[0]);
        printf(CYAN"\nTo edit file pass like this : %s -e -t/-a/-y/-A/-c/-i changing_details mp3filename\n"RESET,argv[0]);
        printf(CYAN"\nTo get help pass like this : %s --help\n"RESET,argv[0]);
     
        return 1;
    }


    //  for view the file details checking th CLA that there is 3 arguments is present or not,1-->./a.out,2--> -v for view, 3--> file name to view.

    if(strcmp(argv[1],"-v")== 0)
    {
       
        if(argc==3)
        {
           view_mp3(argv[2]);
        }
    
       else
       {
          printf(RED BOLD"Invalid Arguments to view file!\n"RESET);
       }
    }



    // for editing the details of file using CLA arguments checking that arguments is coorect or not,if the arrguments is less than 5 print error.1-->./a.out,2-->-e,3-->edit shortcut -y,-a,-A etc,4-->editing details,5-->file name.


   else if(strcmp(argv[1],"-e")== 0)
   {
      if(argc==5)
      {
    
       // valitade the option for editing the title,comments,artist name,and etc.    

        if(strcmp(argv[2],"-y")== 0 || strcmp(argv[2],"-A")== 0 || strcmp(argv[2],"-a")== 0 || strcmp(argv[2],"-t")== 0 || strcmp(argv[2],"-c")== 0 || strcmp(argv[2],"-i")== 0 )
        {
            //  printf("Valid editing option\n");

             edit_mp3(argv[2],argv[3],argv[4]);
        }

        else
        {
            printf(RED BOLD"Invalid editing option\n"RESET);
        }
       
       }

       else
      {
            printf(RED BOLD"Invalid arguments for editing!\n"RESET);
            
       }
   }
   
   else if(strcmp(argv[1],"--help")==0)
   {
         if(argc == 2)
    {
        help();
    }

    } 

    else
    {
         printf(RED BOLD"Invalid command\n"RESET);

    }
    

   


}