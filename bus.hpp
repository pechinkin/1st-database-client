class Bus : public Vehicle
{
private:
    int sitting_pasangers;  //>0
    int max_passangers;     //>=sitting
    std::string destination;
    
public:
    void SetSittingPas(int s);
    void SetMaxPas(int m);
    void SetDestination(std::string d);
    
    int GetSittingPas();
    int GetMaxPas();
    std::string GetDestination();
    
    void WriteTo(std::ostream& output) override{};
    
    Bus();
    ~Bus();
};
