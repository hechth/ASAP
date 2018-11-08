#ifndef PATHOLOGYWORKSTATION_H
#define PATHOLOGYWORKSTATION_H

#include "asaplib_export.h"
#include <QMainWindow>
#include <QDir>
#include <QStringList>
#include <memory>

class MultiResolutionImage;
class QHBoxLayout;
class QAction;
class QStatusBar;
class QMenuBar;
class PathologyViewer;
class WorkstationExtensionPluginInterface;
class QActionGroup;
class QSettings;

/*

OWNERSHIP

Workstation is the owner of all the PathologyViews
Workstation is the owner of all Plugins, also the ToolPlugins generated by ExtensionPlugins
Workstation is the owner of the MultiResolutionImage
Viewer is the owner of RenderThread, TileManager, ScaleBar, MiniMap, RenderWorkers and the Scene

*/

class ASAPLIB_EXPORT ASAP : public QMainWindow
{
  Q_OBJECT

public:
  explicit ASAP(QWidget* parent = 0);
  ~ASAP();

  void setCacheSize(const unsigned long long& cacheMaxByteSize);

  unsigned long long getCacheSize() const;

signals:
  void newImageLoaded(std::weak_ptr<MultiResolutionImage>, const std::string&);
  void imageClosed();

private slots:
  void on_actionClose_triggered();
  void on_actionOpen_triggered();
  void on_actionAbout_triggered();

private:
  static const char* sharedLibraryExtensions;
  std::shared_ptr<MultiResolutionImage> _img;
  unsigned long long _cacheMaxByteSize;
  QSettings* _settings;

  void closeEvent(QCloseEvent *event);
  
  // Plugins
  QDir _pluginsDir;
  std::vector<std::string> _extensionPluginFileNames;
  std::vector<std::string> _toolPluginFileNames;

  // GUI object
  QAction *actionOpen;
  QAction *actionClose;
  QAction *actionAbout;
  QActionGroup *_toolActions;
  QWidget *centralWidget;
  QHBoxLayout *horizontalLayout_2;
  PathologyViewer *pathologyView;
  QMenuBar *menuBar;
  QMenu *menuFile;
  QMenu *menuView;
  QMenu *menuHelp;
  QToolBar *mainToolBar;
  QStatusBar *statusBar;

  // Initialize the GUI
  void initializeDocks();
  void setupUi();
  void retranslateUi();
  void loadPlugins();
  void readSettings();
  void writeSettings();
  void openFile(const QString& fileName, const QString& factoryName = QString("default"));

  std::vector<std::unique_ptr<WorkstationExtensionPluginInterface> > _extensions;
};

#endif // PATHOLOGYWORKSTATION_H
