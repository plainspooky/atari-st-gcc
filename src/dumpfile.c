#include <stdio.h>
#include <stdlib.h>

#define STEPS 8
#define SEP "|"
#define FILEBLOCK 16

unsigned char line_buffer[FILEBLOCK];

void print_in_hex(unsigned char lb[FILEBLOCK]){
    /*
     *  get a segment of FILEBLOCK bytes and print it as a hexadecimal
     *  dump and in ASCII as well.
     */
    unsigned int i, j;

    j = 0;

    for(i=0; i<FILEBLOCK; i++){
	  j++;
        printf("%02x ", lb[i]);
        if (j==STEPS) {
            printf(" ");
            j = 0;
        }
    } // for

    printf(SEP);

    for(i=0; i<FILEBLOCK; i++){
        if (lb[i]>31 && lb[i]<127){
            printf("%c", lb[i]);
        } else {
            printf(".");
        }
    } // for

    puts(SEP);

} // print_in_hex()

int main(int argc, char* argv[]){
    /*
     *  main function
     */

    // file pointer
    FILE *fp;

    unsigned int i, counter;

    if (argc < 2) {
        /*
         *  exit if no arguments were passed at command line
         */
        puts("Must pass an argument!\n");
        exit(1);
    } // if


    if ((fp = fopen(argv[1], "rb")) == NULL){
        /*
         *  exit if file handler is NULL (file not found)
         */
        puts("Error opening file!\n");
        exit(2);
    } // if

    counter = 0;

    /*
     *  while file, do...
     */
    while(!feof(fp)){
        // clear line_buffer
        for(i=0; i<FILEBLOCK; i++) line_buffer[i]=0;

        // get a file block...
        fread(&line_buffer, sizeof(line_buffer), 1, fp);

        // print 'counter', content in hex and ASCII...
        printf("%08x  ", counter);
        print_in_hex(line_buffer);

        counter = counter + FILEBLOCK;
    } // while

    // close file and finish
    fclose(fp);
    return 0;

} // main()
