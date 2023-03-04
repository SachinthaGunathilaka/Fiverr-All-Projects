import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

class PlayerController extends JButton implements ActionListener {
    private static final long serialVersionUID = 1L;
    private static byte values = 0;
    private boolean touch = false;
    private static boolean end = false;
    private int posx = 0, posy = 0;
    private static byte tour = 0;
    private Graphics window;
    ImageIcon x, o;
    private static int[][] mat = new int[3][3];

    public static byte getPath() {
        return tour;
    }

    public static void reset(){
        end = false;
        values = 0;
        tour = 0;
        mat = new int[3][3];
    }
    private void checkWinner(int choix) {
        mat[posx][posy] = choix;
    }

    private void check() {
        for (int i = 0; i < 3; i++) {
            if (mat[i][0] == 1 && mat[i][1] == 1 && mat[i][2] == 1 || mat[0][i] == 1 && mat[1][i] == 1 && mat[2][i] == 1) {
                GameFrame win = new GameFrame("O a gagn�");
                end = true;
                break;
            } else if (mat[i][0] == 2 && mat[i][1] == 2 && mat[i][2] == 2 || mat[0][i] == 2 && mat[1][i] == 2 && mat[2][i] == 2) {
                GameFrame win = new GameFrame("X a gagn�");
                end = true;
                break;
            }
        }
        if (mat[0][0] == 2 && mat[2][2] == 2 && mat[1][1] == 2 || mat[0][2] == 2 && mat[1][1] == 2 && mat[2][0] == 2) {
            GameFrame win = new GameFrame("X a gagn�");
            end = true;
        } else if (mat[0][0] == 1 && mat[2][2] == 1 && mat[1][1] == 1 || mat[0][2] == 1 && mat[1][1] == 1 && mat[2][0] == 1) {
            GameFrame win = new GameFrame("O a gagn�");
            end = true;
        }
        if (tour == 9 && !end) {
            GameFrame win = new GameFrame("Match null");
            end = true;
        }
    }

    public void actionPerformed(ActionEvent e) {
        if (!touch && !end) {
            values++;
            tour++;
            if (values == 3)
                values = 1;
            switch (values) {
                case 1:
                    this.setIcon(x);
                    checkWinner(2);
                    break;
                case 2:
                    this.setIcon(o);
                    checkWinner(1);
                    break;
            }
            check();
        }
        touch = true;
    }

    public PlayerController(int i, int j) {
		x=new ImageIcon(this.getClass().getResource("x.png"));
		o=new ImageIcon(this.getClass().getResource("o.png"));
        posx = i;
        posy = j;
        this.setOpaque(false);
        this.addActionListener(this);
        this.setVisible(true);
        switch (i) {
            case 0:
                switch (j) {
                    case 1:
                        this.setBorder(BorderFactory.createMatteBorder(0, 2, 2, 2, Color.BLACK));
                        break;
                    default:
                        this.setBorder(BorderFactory.createMatteBorder(0, 0, 2, 0, Color.BLACK));
                        break;
                }
                break;
            case 2:
                switch (j) {
                    case 1:
                        this.setBorder(BorderFactory.createMatteBorder(2, 2, 0, 2, Color.BLACK));
                        break;
                    default:
                        this.setBorder(BorderFactory.createMatteBorder(2, 0, 0, 0, Color.BLACK));
                        break;
                }
                break;
            case 1:
                switch (j) {
                    case 1:
                        this.setBorder(BorderFactory.createMatteBorder(2, 2, 2, 2, Color.BLACK));
                        break;
                    default:
                        this.setBorder(BorderFactory.createMatteBorder(2, 0, 2, 0, Color.BLACK));
                        break;
                }
                break;
        }
        this.setContentAreaFilled(false);
        this.setOpaque(false);
    }

}

class GameFrame extends JFrame implements ActionListener {
    private static final long serialVersionUID = 1600441073860748609L;
    JPanel contentPane, botomPane, p;
    JLabel imageLabel, headerLabel;
    JButton retry, exit;
    Box b, bb, bbb;

    void addimages() {
        imageLabel = new JLabel();
        headerLabel = new JLabel();
        retry = new JButton("<html><font size=+2 color=#00991C>Retry</font></html>");
        exit = new JButton("<html><font size=+2 color=#F50300>Exit</font></html>");
        retry.addActionListener(this);
        exit.addActionListener(this);
        b = Box.createHorizontalBox();
        bb = Box.createHorizontalBox();
        p = new JPanel();
        botomPane = new JPanel(new GridLayout(2, 1));
        botomPane.add(retry);
        botomPane.add(exit);
        botomPane.add(bb);
        this.setUndecorated(true);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.contentPane = (JPanel) getContentPane();
        this.contentPane.setLayout(new BorderLayout());
        this.setSize(500, 300);
    }

    void addHeading() {
        headerLabel.setFont(new java.awt.Font("Tic Tac Toe", Font.BOLD, 40));
        String affiche = "<html><font color=#006699>" + "Tic Tac Toe" + "</font></html>";
        headerLabel.setText(affiche);
        b.add(headerLabel);
        p.add(b);
        contentPane.add(p, java.awt.BorderLayout.NORTH);
        ImageIcon ii = new ImageIcon(this.getClass().getResource("victoire.gif"));
        imageLabel.setIcon(ii);
        this.contentPane.add(imageLabel, java.awt.BorderLayout.CENTER);
        this.contentPane.add(botomPane, java.awt.BorderLayout.SOUTH);
        this.setLocationRelativeTo(null);
        this.setVisible(true);
    }

    public GameFrame(String texte) {
        try {
            addimages();
            addHeading();
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == exit) {
            System.exit(0);
        } else if (e.getSource() == retry) {

            TicTacToe.getInstance().init();
            this.dispose();
            PlayerController.reset();

        }
    }
}

class TicTacToe extends JFrame {

    private JPanel pan;
    private PlayerController[][] bouton = new PlayerController[3][3];
    private static TicTacToe ticTacToe = new TicTacToe();
    public static TicTacToe getInstance(){
        return ticTacToe;
    }

    public TicTacToe() {
        this.setTitle("Tic Tac Toe");
        this.setSize(450, 450);
        this.setResizable(false);
    }

    void init() {
        this.getContentPane().removeAll();
        this.repaint();

        pan = new JPanel(new GridLayout(3, 3));

        for (int x = 0; x < 3; x++) {
            for (int j = 0; j < 3; j++) {

                pan.add(bouton[x][j] = new PlayerController(x, j));

            }
        }

        pan.setBackground(Color.WHITE);
        this.add(pan, BorderLayout.CENTER);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
    }

}

public class Main {
    public static void main(String[] args) {
        TicTacToe.getInstance().init();
    }


}
