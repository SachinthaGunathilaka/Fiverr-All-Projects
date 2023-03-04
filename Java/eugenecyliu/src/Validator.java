import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.awt.image.DataBufferByte;
import java.io.File;

public class Validator {
    public byte[] img1;
    public byte[] img2;

    public void compare(String fileName1, String fileName2) {
        try {
            BufferedImage b1 = (ImageIO.read(new File(fileName1)));
            img1 = ((DataBufferByte) b1.getRaster().getDataBuffer()).getData();

            BufferedImage b2 = (ImageIO.read(new File(fileName2)));
            img2 = ((DataBufferByte) b2.getRaster().getDataBuffer()).getData();

            System.out.println(b1.getHeight() + " " + b1.getWidth());
            System.out.println(b2.getHeight() + " " + b2.getWidth());

            int len = b1.getWidth() * b1.getHeight();
            System.out.println(len);
//
            for (int i = 0; i < len; i++) {
                if (img1[i] != img2[i]) {
                    System.out.println("Invalid");
                    break;
                }
            }

            System.out.println("Valid");
        } catch (Exception ee) {

            ee.printStackTrace();
        }
    }


}
