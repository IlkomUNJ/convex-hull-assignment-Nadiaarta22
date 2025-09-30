#ifndef DRAWINGWIDGET_H
#define DRAWINGWIDGET_H

#include <QWidget>
#include <QPointF>
#include <vector>

class DrawingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DrawingWidget(QWidget *parent = nullptr);

public slots:
    void runConvexHull();
    void clearAll();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    std::vector<QPointF> points;
    std::vector<QPointF> hull_slow;
    std::vector<QPointF> hull_fast;

    long long iter_slow = 0;
    long long iter_fast = 0;
    long long sort_comparisons = 0;

    static double orient(const QPointF &a, const QPointF &b, const QPointF &c, long long &counter);
    std::vector<QPointF> bruteForceHull(const std::vector<QPointF> &pts, long long &counter);
    std::vector<QPointF> monotoneChain(std::vector<QPointF> pts, long long &iter, long long &sort_comps);

    static bool nearlyEqual(double a, double b);
};

#endif // DRAWINGWIDGET_H
