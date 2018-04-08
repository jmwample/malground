
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
void print_to_buffer(){
    asm volatile(
        "mov  $0x7A7A6946, %%rax\n"
        "push %%rax\n"
        "mov $0x1, %%rax\n"
        "mov $0x1, %%rdi\n"
        "mov %%rsp, %%rsi\n" // *buff_i
        "mov $0x04, %%rdx\n" // length 
        "syscall\n"
        ::: "rsp", "rdi", "rsi", "rdx");
    return;
}*/

void pack_XOR (uint8_t *key, unsigned int length, unsigned int  key_len, uint8_t *buff_i, uint8_t *buff_o){
    
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int trailing_chars = (length % key_len == 0)? key_len : length % key_len;
    unsigned int pen_len = length-trailing_chars; // length to end of penultimate key length

    // Process all complete key lengths
    for (i=0; i<pen_len; i+=key_len){
        for (j=0;j<key_len;j++){
            buff_o[i+j] = buff_i[i+j] ^ key[j];
        }  
    }

    // Process ultimate block - not always complete
    for (j=0;j<trailing_chars;j++){
        buff_o[pen_len + j] = buff_i[pen_len + j] ^ key[j];
    }
}



void print_buff(uint8_t *buff, unsigned int len) {
    for (int i=0; i<len;i++){
        printf("%02X", buff[i]);
    }
    printf("\n");
}


int main(){
    
    uint8_t key[] = {0x02,0x6f,0x86,0xf8,0x39};
    
    unsigned int length = 50;

    unsigned int key_length = 5;

    uint8_t *buff_out;
    uint8_t *buff_final;
    
    uint8_t buff_in[] = {
            0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,
            0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,
            0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,
            0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,
            0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42};
                
    buff_out = malloc((length)*sizeof(uint8_t));
    buff_final = malloc((length)*sizeof(uint8_t));

    print_buff(buff_in, length );
    pack_XOR(key, length, key_length, buff_in, buff_out);

    print_buff(buff_out, length );

    pack_XOR(key, length, key_length, buff_out, buff_final);

    print_buff(buff_final, length );

    free(buff_out);
    free(buff_final);
}





