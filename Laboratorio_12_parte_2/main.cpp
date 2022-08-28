#include <opencv2/opencv.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace cv;

int main(){
	int arr[5][5]{};
	srand(static_cast<unsigned int>(time(nullptr)));
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			arr[i][j] = rand() % 10 + 1;

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j)
			std::cout << arr[i][j] << "\t";
		std::cout << "\n";
	}

	Mat img = cv::imread("D:/COMPUTACION GRAFICA/OPENCV/src/Laboratorio_12/test.jpg", cv::IMREAD_COLOR);
	
	if (img.empty()) {
		std::cout << "Error al cargar la imagen" << std::endl;
		return -1;
	}
	

	Mat imgBlue = img.clone();
	for (int row = 0; row < imgBlue.rows; ++row) {
		for (int col = 0; col < imgBlue.cols; ++col) {
			cv::Vec3b& color = imgBlue.at<cv::Vec3b>(row, col);

			color[1] = 0;
			color[2] = 0;
		}
	}

	imshow("Imagen original", img);
	
	imshow("Imangen con solo canal azul", imgBlue);
	waitKey();
	destroyAllWindows();
	
	// Cambiar imagen a escala de grises
	Mat imgGrayScale;
	cvtColor(img, imgGrayScale, COLOR_BGR2GRAY);

	imshow("Imagen original", img);
	imshow("Imagen en escala de grises", imgGrayScale);
	waitKey();
	destroyAllWindows();

	// Guardar una nueva imagen que contenga solo los canales rojo y verde
	Mat imgRedGreen = img.clone();
	for (int row = 0; row < imgRedGreen.rows; ++row) {
		for (int col = 0; col < imgRedGreen.cols; ++col) {
			cv::Vec3b& color = imgRedGreen.at<cv::Vec3b>(row, col);

			color[0] = 0;
		}
	}

	imshow("Imagen original", img);
	imshow("Imagen con solo canal rojo y verde", imgRedGreen);
	imwrite("test_Red_Green.jpg", imgRedGreen);
	waitKey();
	destroyAllWindows();

	// Guarden una nueva imagen que muestre la imagen en escala de grises
	imshow("Imagen original", img);
	imshow("Imagen en escala de grises", imgGrayScale);
	imwrite("test_Gray_scale.jpg", imgGrayScale);
	
	waitKey();
	destroyAllWindows();
	

	return 0;
}