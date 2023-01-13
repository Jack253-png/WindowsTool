class SRGBColor {
    public:
        SRGBColor(int r, int g, int b);
        SRGBColor();
        ~SRGBColor();
        int getRed();
        int getGreen();
        int getBlue();
    private:
        int red;
        int green;
        int blue;
};