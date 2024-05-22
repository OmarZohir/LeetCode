class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        std::string str = std::bitset<32>(n).to_string();
        //reverse position for each element
        for (int i =0; i < 16; ++i){
          char temp = str[i];
          str[i] = str[31-i];
          str[31-i] = temp;   
        }
        uint32_t str_int = std::bitset<32>(str).to_ulong();
        return str_int;
    }
};