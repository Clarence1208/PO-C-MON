int main(argc, ** argv)
{
    int x, y;
    for(y=0; y<16; y++)
    {
        for(x=0; x<16; x++)
        {
            float p = perlin2d(x, y, 0.1, 4);
            printf("%c", (int)(p*9)%10 + '0');
        }
        printf("\n");
    }
    return 0;
}