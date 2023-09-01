class Core
{
public:
    static Core& instance()
    {
        static Core t;
        return t;
    }
    Core& operator=(const Core&) = delete;
    Core(const Core&) = delete;
    Core(Core&&) = delete;
    Core& operator=(Core&&) = delete;
private:
    Core() = default;
};