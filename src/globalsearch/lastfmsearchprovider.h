/* This file is part of Clementine.
   Copyright 2010, David Sansome <me@davidsansome.com>

   Clementine is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Clementine is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Clementine.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef LASTFMSEARCHPROVIDER_H
#define LASTFMSEARCHPROVIDER_H

#include "searchprovider.h"

class LastFMService;

class LastFMSearchProvider : public BlockingSearchProvider {
  Q_OBJECT

public:
  LastFMSearchProvider(LastFMService* service, QObject* parent);

  static const int kResultLimit;

  void LoadArtAsync(int id, const Result& result);
  void LoadTracksAsync(int id, const Result& result);

protected:
  ResultList Search(int id, const QString& query);

private slots:
  void RecreateItems();

private:
  LastFMService* service_;

  QImage icon_;

  struct Item {
    QString keyword_;
    Song metadata_;
  };

  QMutex items_mutex_;
  QList<Item> items_;
};

#endif // LASTFMSEARCHPROVIDER_H
