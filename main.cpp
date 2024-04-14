#include <iostream>

void invert(uint8_t* bts, size_t length, size_t start, size_t end)
{
    for (size_t i = 0; i < length; ++i)
    {
        uint8_t memory_byte = bts[i];
        uint8_t mask = ((1 << (end - start + 1)) - 1) << start;
        bts[i] = memory_byte ^ mask;
    }
}

void print(uint8_t* bts, size_t length)
{
    for (size_t i = 0; i < length; ++i)
        std::cout << std::bitset<8>(bts[i]) << std::endl;
}

bool check_range(size_t value, size_t range_start, size_t range_end)
{
    if (value > range_start && value < range_end)
        return true;
    return false;
}

int main()
{
    size_t start = 0;
    size_t end = 0;

    uint8_t bts[] = {0b11111100,
                      0b11101110,
                      0b01001000,
                      0b10000101,
                      0b10010001};

    size_t length = sizeof(bts);

    print(bts, length);
    std::cout << "length: " << length << std::endl;

    do
    {
        std::cout << "\nYou need to enter two values so that the start position value is "
                     "less than or equal to the end position value, and you also need the start and end position "
                     "values to fall within the range 0 - 7, otherwise the entry will be repeated\n" << std::endl;
        std::cout << "Enter a start position: ";
        std::cin >> start;
        std::cout << "Enter a end position: ";
        std::cin >> end;
    }
    while(start > end || !check_range(start, 0, 7) || !check_range(end, 0, 7));

    std::cout << "Inversion occurs from right to left" << std::endl;
    invert(bts, length, start, end);

    print(bts, length);

    return 0;
}