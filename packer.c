
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
void print_HW(){
    // ['0x48', '0x65', '0x6c', '0x6c', '0x6f', '0x20', '0x57', '0x6f', '0x72', '0x6c', '0x64', '0x21']
    asm volatile(
        "mov  $0x0A21646C72, %%rax\n"
        "push %%rax\n"
        "mov  $0x6F57206F6C6C6548, %%rax\n"
        "push %%rax\n"
        "mov %%rsp, %%rsi\n" 
        "mov $0x1, %%rax\n"
        "mov $0x1, %%rdi\n"
        "mov $0x0D, %%rdx\n" 
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
    uint8_t key1[] = {0x02,0x6f,0x86,0xf8,0x39};
    uint8_t key2[] = {0x9a,0xaa,0x04,0x79,0x47,0xec,0x5d,0xe2};
    
    unsigned int length = 48;

    unsigned int key_length = 5;

    uint8_t *buff_out;
    uint8_t *buff_final;
    
    uint8_t buff_hw[] = {
            0x48,0xb8,0x72,0x6c,0x64,0x21,0x0a,0x00,
            0x00,0x00,0x50,0x48,0xb8,0x48,0x65,0x6c,
            0x6c,0x6f,0x20,0x57,0x6f,0x50,0x48,0x89,
            0xe6,0x48,0xc7,0xc0,0x01,0x00,0x00,0x00,
            0x48,0xc7,0xc7,0x01,0x00,0x00,0x00,0x48,
            0xc7,0xc2,0x0d,0x00,0x00,0x00,0x0f,0x05};

    uint8_t buff_in[] = {
            0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,
            0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,
            0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,
            0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,
            0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42};
                
    buff_out = malloc((length)*sizeof(uint8_t));
    buff_final = malloc((length)*sizeof(uint8_t));

    print_buff(buff_hw, length );
    pack_XOR(key2, length, key_length, buff_hw, buff_out);

    print_buff(buff_out, length );

    pack_XOR(key1, length, key_length, buff_out, buff_final);

    print_buff(buff_final, length );

    pack_XOR(key2, length, key_length, buff_final, buff_out);
    pack_XOR(key1, length, key_length, buff_out, buff_final);

    print_buff(buff_final, length );

    free(buff_out);
    free(buff_final);
}





