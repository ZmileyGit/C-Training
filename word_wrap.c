#include <stdio.h>

#define COLUMN_LIMIT 100
#define NO_BLANK -1

#define NORMAL_LINE 0
#define LARGE_LINE 1

void print_buffer(char buffer[],int from,int to);
void print_buffer_up_to(char buffer[],int to);

int main(){
    int cursor,allocator,residue;
    int last_blank = -1, status = NORMAL_LINE;
    char buffer[COLUMN_LIMIT];
    
    allocator = 0;

    while(residue != '\0' || (cursor = getchar())!= EOF){
        if(residue != '\0'){
            cursor = residue;
            residue = '\0';
        }
        if(cursor == ' '){
            last_blank = allocator;
        }
        if(cursor == '\n'){
            if(status == NORMAL_LINE){
                print_buffer_up_to(buffer,allocator);
            }else if(status == LARGE_LINE){
                putchar('>');
                print_buffer_up_to(buffer,allocator);
            }
            putchar(cursor);
            allocator = 0;
            last_blank = NO_BLANK;
            status = NORMAL_LINE;
        }else if( allocator == COLUMN_LIMIT ){
            if(last_blank == NO_BLANK){
                //printf("No blank\n");
                if(status == NORMAL_LINE){
                    status = LARGE_LINE;
                    print_buffer_up_to(buffer,COLUMN_LIMIT);
                    putchar('<');
                }else if(status == LARGE_LINE){
                    putchar('>');
                    print_buffer_up_to(buffer,COLUMN_LIMIT);
                    putchar('<');
                }
                putchar('\n');
                allocator = 0 ;
                last_blank = NO_BLANK;
                residue = cursor;
                status = LARGE_LINE;
            }else{
                //printf("With blank %d\n",last_blank);
                if(status == NORMAL_LINE){
                    print_buffer_up_to(buffer,last_blank);
                }else if(status == LARGE_LINE){
                    putchar('>');
                    print_buffer_up_to(buffer,last_blank);
                }
                putchar('\n');
                allocator = 0;
                for(int count=(last_blank + 1);count < COLUMN_LIMIT;++count){
                    buffer[allocator] = buffer[count];
                    ++allocator;    
                }
                last_blank = NO_BLANK;
                if(cursor != ' '){
                    residue = cursor;
                }
                status = NORMAL_LINE;
            }
        }else if(allocator < COLUMN_LIMIT){
            buffer[allocator] = cursor;
            ++allocator;
        }
    }
    if(status == NORMAL_LINE){
        print_buffer_up_to(buffer,allocator);
    }else if(status == LARGE_LINE){
        putchar('>');
        print_buffer_up_to(buffer,allocator);
    }
    putchar('\n');
}

void print_buffer(char buffer[],int from,int to){
    for(;from < to;++from){
        putchar(buffer[from]);
    }
}

void print_buffer_up_to(char buffer[],int to){
    print_buffer(buffer,0,to);
}