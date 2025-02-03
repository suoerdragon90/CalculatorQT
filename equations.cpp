#include "equations.h"
#include "ui_equations.h"

EquaTions::EquaTions(QWidget *parent)
    : QWidget(parent), ui(new Ui::EquaTions), Tables(nullptr), simple(nullptr), logic(nullptr) {
    ui->setupUi(this);
    setWindowTitle("Equations");

    // Keep original path but add fallback to relative path
    backgroundPixmap = QPixmap("/build/Desktop_Qt_6_8_1_MinGW_64_bit-Debug/Media/background/bg1.png");
    logoPixmap = QPixmap("D:/Data Structure Project/Discreete_Finale_forreal/Discreete/build/Desktop_Qt_6_8_1_MinGW_64_bit-Debug/Media/background/logo.ico");

    // If original paths fail, try relative paths
    if (backgroundPixmap.isNull()) {
        QString appDir = QCoreApplication::applicationDirPath();
        backgroundPixmap = QPixmap(appDir + "/Media/background/bg1.png");
        if (backgroundPixmap.isNull()) {
            qDebug() << "Failed to load background image from both paths";
        }
    }

    if (logoPixmap.isNull()) {
        QString appDir = QCoreApplication::applicationDirPath();
        logoPixmap = QPixmap(appDir + "/Media/background/logo.ico");
        if (logoPixmap.isNull()) {
            qDebug() << "Failed to load logo from both paths";
        }
    }

    setWindowIcon(QIcon(logoPixmap));
}

EquaTions::~EquaTions() {
    if (Tables) { Tables->close(); delete Tables; }
    if (simple) { simple->close(); delete simple; }
    if (logic) { logic->close(); delete logic; }
    delete ui;
}

void EquaTions::closeEvent(QCloseEvent *event) {
    if (Tables) { Tables->close(); }
    if (simple) { simple->close(); }
    if (logic) { logic->close(); }
    event->accept();
}

void EquaTions::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    // Draw background with opacity
    if (!backgroundPixmap.isNull()) {
        qreal opacity = 0.5;
        painter.setOpacity(opacity);
        painter.drawPixmap(0, 0, width(), height(), backgroundPixmap);
    }

    // Draw logo
    if (!logoPixmap.isNull()) {
        int logoSize = 32;  // Set a reasonable size for the logo
        painter.setOpacity(1.0);  // Reset opacity for logo
        painter.drawPixmap(10, 10, logoSize, logoSize, logoPixmap);
    }
}

void EquaTions::on_p1_clicked() {
    if (!Tables) { Tables = new TabLes(); }
    Tables->show();
}

void EquaTions::on_p2_clicked() {
    if (!logic) { logic = new class logic(); }
    logic->show();
}

void EquaTions::on_p3_clicked() {
    if (!simple) { simple = new class simple(); }
    simple->show();
}

void EquaTions::on_EQ_Solve_clicked() {
    // Get values from combo boxes and convert them to booleans
    bool P = ui->comboBox_EQ_P->currentText() == "True";
    bool Q = ui->comboBox_EQ_Q->currentText() == "True";
    bool R = ui->comboBox_EQ_R->currentText() == "True";

    // Evaluate the logical expression
    bool result = evaluateExpression(P, Q, R);

    // Display the result in EQ_Result label
    ui->EQ_Result->setText(result ? "True" : "False");
}

bool EquaTions::evaluateExpression(bool P, bool Q, bool R) {
    // Calculate ¬P, ¬Q, and ¬(¬Q ∧ R)
    bool notP = !P;
    bool notQ = !Q;
    bool not_Q_and_R = !(notQ && R);

    // Calculate ¬P ∨ ¬Q
    bool notP_or_notQ = notP || notQ;

    // Evaluate (¬P ∨ ¬Q) → ¬(¬Q ∧ R)
    return !notP_or_notQ || not_Q_and_R;  // Implication: A → B is equivalent to !A || B
}
