pipeline {
    agent any

    stages {

        stage('Checkout') {
            steps {
                checkout scm
            }
        }

        stage('Build ESP32') {
            steps {
                bat '''
                    set PATH=C:\\Espressif\\tools\\python\\v6.0.1\\venv\\Scripts;C:\\esp\\v6.0.1\\esp-idf;%PATH%

                    call C:\\esp\\v6.0.1\\esp-idf\\export.bat

                    python --version
                    python C:\\esp\\v6.0.1\\esp-idf\\tools\\idf.py build
                '''
            }
        }
    }
}
