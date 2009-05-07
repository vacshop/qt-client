/*
 * This file is part of the xTuple ERP: PostBooks Edition, a free and
 * open source Enterprise Resource Planning software suite,
 * Copyright (c) 1999-2009 by OpenMFG LLC, d/b/a xTuple.
 * It is licensed to you under the Common Public Attribution License
 * version 1.0, the full text of which (including xTuple-specific Exhibits)
 * is available at www.xtuple.com/CPAL.  By using this software, you agree
 * to be bound by its terms.
 */

#ifndef comments_h
#define comments_h

#include <xsqlquery.h>

#include "xtreewidget.h"

class QPushButton;
class XTreeWidget;

class XTUPLEWIDGETS_EXPORT Comments : public QWidget
{
  Q_OBJECT

  Q_ENUMS(CommentSources)

  Q_PROPERTY(CommentSources type READ type WRITE setType)

  friend class Comment;

  public:
    Comments(QWidget *, const char * = 0);

    // if you add to this then add to the _commentMap[] below
    enum CommentSources
    {
      Uninitialized,
      Address,
      BBOMHead,		BBOMItem,
      BOMHead,		BOMItem,
      BOOHead,		BOOItem,
      CRMAccount,	Contact,	Customer,
      Employee,         Incident,
      Item,		ItemSite,	ItemSource,
      Location,		LotSerial,
      Opportunity,
      Project,		PurchaseOrder,	PurchaseOrderItem,
      ReturnAuth, ReturnAuthItem, Quote, QuoteItem,
      SalesOrder,	SalesOrderItem, Task,
      TodoItem,      TransferOrder,	TransferOrderItem,
      Vendor,
      Warehouse,	WorkOrder
    };

    inline int sourceid()             { return _sourceid; }
    inline enum CommentSources type() { return _source;   }

    struct CommentMap
    {
      enum CommentSources source;
      QString             ident;

      CommentMap(enum CommentSources s, const QString & i)
      {
        source = s;
        ident = i;
      }
    };
    static const struct CommentMap _commentMap[]; // see comments.cpp for init

  public slots:
    void setType(enum CommentSources);
    void setId(int);
    void setReadOnly(bool);

    void sNew();
    void sView();
    void refresh();
    
  signals:
    void commentAdded();

  private:
    enum CommentSources _source;
    int                 _sourceid;
    QList<QVariant> _commentIDList;

    XTreeWidget *_comment;
    QPushButton *_newComment;
    QPushButton *_viewComment;
};

#endif
