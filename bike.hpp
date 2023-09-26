class Bike : public Vehicle
{
private:
    int engine_volume;  //>0
    int power;          //>0
    int landscape;      //1, 2 or 3
    
public:
    void SetVolume(int v);
    void SetPower(int p);
    void SetLandscape(int l);
    
    int GetVolume();
    int GetPower();
    int GetLandscape();
    
//    void WriteTo(std::ostream& output) override;
    
};

void Bike::SetVolume(int v)
{
    engine_volume = v;
};
void Bike::SetPower(int p)
{
    power = p;
};
void Bike::SetLandscape(int l)
{
    landscape = l;
};

int Bike::GetVolume()
{
    return engine_volume;
};
int Bike::GetPower()
{
    return power;
};
int Bike::GetLandscape()
{
    return landscape;
};
