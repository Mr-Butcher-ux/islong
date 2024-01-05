#include       <stdio.h>
#include       <sys/types.h>
#include       <dirent.h>
#include       <sys/stat.h>

int do_ls(char* );
int do_stat( char*);

int main(int ac, char *av[])
{
       if ( ac == 1 )
               do_ls( "." );
       else
       {
                while ( --ac ){
                        printf("%s:\n", *++av );
                        do_ls( *av );
                }
       }
}
int do_ls( char *dirname )
{
        DIR   *dir_ptr; /* the directory */
        struct dirent *direntp; /* each entry */

    if ( ( dir_ptr = opendir( dirname ) ) == NULL )
       fprintf(stderr,"lslong: cannot open %s\n", dirname);
    
    else
        {

    while ( ( direntp = readdir( dir_ptr ) ) != NULL )
        
        do_stat( direntp->d_name);
        closedir(dir_ptr);
        }
   
    return 0;
    
}



int do_stat( char *filename )
{
       struct stat info;
       
    printf("%s:\n", filename );
    if ( stat(filename, &info) == -1 )
        perror( filename);
else
        {
                printf("\t mode: %o\n", (int) info.st_mode);
                printf("\t links:%d\n", (int) info.st_nlink);
                printf("\t owner: %d\n", (int) info.st_uid);
                printf("\t group: %d\n", (int) info.st_gid);
                printf("\t size: %ld\n",(long)info.st_size);
                printf("\t mod:%ld\n",(long)info.st_mtime);
                printf("\taccess: %ld\n",(long)info.st_atime);

        }
    return 0;
}

