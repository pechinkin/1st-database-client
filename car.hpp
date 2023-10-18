class Car : public Vehicle
{
private:
    int engine_volume;  //>0
    int color;
    char gearbox;       //a - automatic, m - manual, r - robotized, с - continuously variable transmission
    
public:
    void SetVolume(int v);
    void SetColor(int c);
    void SetGearbox(char g);
    void SetType() override;
    
    int GetVolume() const;
    int GetColor() const;
    char GetGearbox() const;
    
//    void WriteTo(std::ostream& output) override;
    std::ostream& WriteTo(std::ostream& output) const override;
    
    
    Car();
    Car(std::string b, std::string m, int v, int c, char g);
    Car(Car const &another);
};

void Car::SetVolume(int v)
{
    engine_volume = v;
};
void Car::SetColor(int c)
{
    color = c;
};
void Car::SetGearbox(char g)
{
    gearbox = g;
};
void Car::SetType()
{
    type = 'r';
};


int Car::GetVolume() const
{
    return engine_volume;
};
int Car::GetColor() const
{
    return color;
};
char Car::GetGearbox() const
{
    return gearbox;
};

std::ostream& Car::WriteTo(std::ostream& output) const {
    output << "Brand: " << GetBrand() << ", Model: " << GetModel() << ", Engine Volume: "
    << engine_volume << ", Color: " << color << ", Gearbox: " << gearbox;
    return output;
}

Car::Car(): Vehicle()
{
    engine_volume = 0;  //>0
    color = 0;
    gearbox = '-';
    SetType();
};
Car::Car(std::string b, std::string m, int v, int c, char g):
Vehicle(b, m), engine_volume{v}, color{c}, gearbox{g}
{
    SetType();
};
Car::Car(Car const &another):
Vehicle(another.GetBrand(), another.GetModel()), engine_volume{another.GetVolume()},
color{another.GetColor()}, gearbox{another.GetGearbox()}
{
    SetType();
};
