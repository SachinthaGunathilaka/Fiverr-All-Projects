import java.awt.image.BufferedImage;
import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Objects;


import com.idrsolutions.image.JDeli;
import com.idrsolutions.image.pdf.options.PdfEncoderOptions;
import com.lowagie.text.pdf.PdfWriter;
import org.apache.pdfbox.Loader;
import org.apache.pdfbox.pdmodel.PDDocument;
import org.apache.pdfbox.pdmodel.PDPage;
import org.apache.pdfbox.pdmodel.PDPageContentStream;
import org.apache.pdfbox.pdmodel.common.PDRectangle;
import org.apache.pdfbox.rendering.PDFRenderer;

import org.opencv.core.Core;
import org.opencv.core.Mat;

import org.opencv.core.Rect;
import org.opencv.imgcodecs.Imgcodecs;

import javax.imageio.ImageIO;
import javax.swing.text.Document;


public class Main {


//    public static void imageToPDF(String filename) throws Exception {
//        PDDocument document = new PDDocument();
//        InputStream in = new FileInputStream(filename);
//        BufferedImage bimg = ImageIO.read(in);
//        float width = bimg.getWidth();
//        float height = bimg.getHeight();
//        PDPage page = new PDPage(new PDRectangle(width, height));
//        document.addPage(page);
//        PDXObjectImage img = new PDJpeg(document, new FileInputStream(filename));
//        PDPageContentStream contentStream = new PDPageContentStream(document, page);
//        contentStream.drawImage(img, 0, 0);
//        contentStream.close();
//        in.close();
//
//        document.save("test.pdf");
//        document.close();
//    }

    public static boolean isWhite(double[] pixel) {
        return pixel[0] > 200 && pixel[1] > 180 && pixel[2] > 140;

    }

    public static int readImage(String pdf_name, String filepath, int q_num) throws Exception {
        Mat img = Imgcodecs.imread(filepath);

        int white_rows = 0;
        int black_rows = 0;
        int white_rows_limit = 150;
        int black_rows_limit = 350;
        int splitting_positions = 0;

//        Splitsplit = new Split();
        ArrayList<Split> splits = new ArrayList<>();

        boolean detected_flag = false;
        Split split = new Split();
        int count = 0;
        for (int i = 0; i < img.rows(); i++) {

            boolean gap1 = true;
            for (int j = 2020; j < 2050; j++) {
                if (!isWhite(img.get(i, j))) {
                    gap1 = false;
                    break;
                }
            }

            boolean number = false;
            for (int j = 2050; j < 2120; j++) {
                if (!isWhite(img.get(i, j))) {
                    number = true;
                    break;
                }
            }

            boolean gap2 = true;
            for (int j = 2120; j < img.cols(); j++) {
                if (!isWhite(img.get(i, j))) {
                    gap2 = false;
                    break;
                }
            }

            if (gap1 && gap2 && number) {
                if (count == 20) {

                    if (detected_flag) {
                        split.setEnd(i);
                        splits.add(split);
                    }
//                    System.out.println("Number found " + i);
                    detected_flag = true;
                    split = new Split();
                    split.setStart(i);
                    i += 100;
                    count = 0;
                }
                count++;
            }

            if (detected_flag) {
                if (white_rows == white_rows_limit) {
                    split.setEnd(i);
                    splits.add(split);
                    detected_flag = false;
//                    System.out.println("white " + i);
                }
                int white_pixel_count = 0;
                for (int j = 0; j < img.cols(); j++) {

                    if (isWhite(img.get(i, j))) {
                        white_pixel_count++;
                    }
                }

                if (white_pixel_count == img.cols()) {
                    white_rows++;
                } else {
                    white_rows = 0;
                }
            }


        }

        if (detected_flag) {
            split.setEnd(2700);
            splits.add(split);
        }

//        return 1;


        int i = 1;
        for (Split split1 : splits) {
//            System.out.println(split1.getStart() + "  " + split1.getEnd());


            Rect roi = new Rect(0, split1.getStart() - 60, img.cols(), split1.getEnd() - split1.getStart() - 30);
            Mat cropped = new Mat(img, roi);

            Files.createDirectories(Paths.get("Output/" + pdf_name + "_Q" + q_num));

//            System.out.println("Output/" + pdf_name + "/question" + q_num + ".jpeg");
            Imgcodecs.imwrite("Output/" + pdf_name + "_Q" + q_num + "/question" + q_num + ".jpeg", cropped);
//            imageToPDF("Output/" + pdf_name + "_Q" + q_num + "/question" + q_num + ".jpeg");
            q_num++;
            i++;
        }

        return q_num;


    }

    public static void main(String[] args) throws IOException {
        System.loadLibrary(Core.NATIVE_LIBRARY_NAME);
        String input_folder = "Input";


        File directory = new File(input_folder);
        for (File file_1 : Objects.requireNonNull(directory.listFiles())) {
            try {
                if (Objects.equals(file_1.getName().split("\\.")[1], "pdf")) {
//                    System.out.println("\n\n" + file_1.getName());
                    File file = new File(input_folder + "/" + file_1.getName());
                    PDDocument document = Loader.loadPDF(file);
                    int num_of_pages = document.getNumberOfPages();

                    PDFRenderer pdfRenderer = new PDFRenderer(document);
                    int q_num = 1;
                    for (int i = 1; i < 6; i++) {
                        BufferedImage img = pdfRenderer.renderImage(i, 4);

                        String image_name = "Output/" + file_1.getName().split("\\.")[0] + " page " + i + ".jpeg";
//                        System.out.println(image_name);
                        ImageIO.write(img, "JPEG", new File(image_name));
//                        System.out.println("Image has been extracted successfully");

                        q_num = readImage(file_1.getName().split("\\.")[0], image_name, q_num);


                    }
                    System.out.println(file_1.getName() + " extracted successfully!");


                    document.close();

                }
            } catch (Exception e) {

            }


        }

        File folder = new File("Output");
        File[] fList = folder.listFiles();

        for (File f : fList) {
            if (f.getName().endsWith(".jpeg")) {
                f.delete();
            }
        }


    }
}