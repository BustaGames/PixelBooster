/***************************************************************************\
*  Pixel::Booster, a simple pixel art image editor.                         *
*  Copyright (C) 2015  Ricardo Bustamante de Queiroz (ricardo@busta.com.br) *
*  Visit the Official Homepage: pixel.busta.com.br                          *
*                                                                           *
*  This program is free software: you can redistribute it and/or modify     *
*  it under the terms of the GNU General Public License as published by     *
*  the Free Software Foundation, either version 3 of the License, or        *
*  (at your option) any later version.                                      *
*                                                                           *
*  This program is distributed in the hope that it will be useful,          *
*  but WITHOUT ANY WARRANTY; without even the implied warranty of           *
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
*  GNU General Public License for more details.                             *
*                                                                           *
*  You should have received a copy of the GNU General Public License        *
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.    *
\***************************************************************************/

#ifndef ACTION_HANDLER_H
#define ACTION_HANDLER_H

#include <QObject>
#include <QMap>

class GlobalOptions;
class MainWindow;
class QAction;

/*!
 * \brief The ActionHandler class
 */
class ActionHandler : public QObject {
  Q_OBJECT
public:
  explicit ActionHandler(QObject *parent);
  virtual ~ActionHandler();

  void RegisterTool(QAction *tool, int val);
  QAction *GetTool(int val);

public slots:
  // File Actions
  void NewFile() const;
  void OpenFile() const;
  void SaveFile() const;
  void SaveAll() const;
  void SaveAs() const;

  bool CloseWindowHandler() const;

  // Other Actions
  void Undo() const;
  void Redo() const;

  // Tools
  void ToolPressed(QAction *a) const;

  // Interface Actions
  void About() const;
  void TileSize() const;
  void ToggleTransparency(bool transparency) const;
  void Zoom(int zoom) const;
  void OpenMainColorPick() const;
  void OpenAltColorPick() const;
  void SetMainColor(const QColor &color) const;
  void SetAltColor(const QColor &color) const;
  void SwapColors() const;
  void SetColorGradient() const;
  void LoadPalette() const;
  void SavePalette() const;
  void DefaultPalette() const;
  void LoadSavedPalette() const;
  void ToggleShowGrid(bool show) const;
  void ToggleShowPixelGrid(bool show) const;
  void ImageSize() const;

  // Language Actions
  void Translate(const QString &language) const;
  void TranslatePT_BR() const;
  void TranslateEN_US() const;

signals:
  void UpdateEditArea() const;

private:
  GlobalOptions *options_cache_;
  MainWindow *window_cache_;
  QMap<QAction *, int> tool_action_map_;

  void CreateImageCanvas(const QImage &image, const QString &file_name) const;
};

#endif // ACTION_HANDLER_H
