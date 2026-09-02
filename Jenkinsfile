pipeline {
    agent any

    stages {
        stage('Build ESP32') {
            steps {
                bat '''
                    call C:\\esp\\v6.0.1\\esp-idf\\export.bat
                    idf.py build
                '''
            }
        }
    }
}
