#pragma once
#include <QMainWindow>
#include <set>

#include "ui_MainWindow.h"
#include "AboutWindow.hpp"
#include "DialogWindow.hpp"

#include "MHMemory.hpp"
#include "json.hpp"

// for convenience
using json = nlohmann::json;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void debugPrints() const ;
    void show();

    fs::path SettingsFile = CurrentExecutableDir().append("Settings.json");
    fs::path SavedSetsFile = CurrentExecutableDir().append("SavedSets.json");
    fs::path ArmorDataFile = CurrentExecutableDir().append("ArmorData.json");

  private:
    Ui::MainWindow *ui;
    MH_Memory _MHManager;
    json _Settings;
    json _SavedSets;
    json _ArmorData;
    bool _ArmorDataFound;
    std::array<QComboBox*,5> _InputBoxes = {nullptr,nullptr,nullptr,nullptr,nullptr};
    std::set<std::string> _UnSafeArmors;
    std::array<int,5> _SafeCount = {0,0,0,0,0};

private slots:
    void _Instructions();
    void _aboutInfo();

    void _FindAddr();
    void _PopulateComboBoxes();
    bool _LoadConfigFiles();
    
    bool _ParseInputBoxes();
    void _WriteData();
    void _SaveCurrentSet();

    void _UpdateArmorValues();
    void _FetchData(bool noMessage = false);
    void _LoadSavedSet();
    void _ClearArmor();
    void _ChangeAll();

    bool _FlushSavedSets();
    bool _FlushSettings();
    void _GetCustomSteamPath();

    void _UnsafeWarning();
    void _ToggleSafe();
    void _AddUnsafe();
    void _DeleteUnsafe();

    void _NotImplemented();
};