pipeline {
    agent any

    stages {
        stage('Build ESP32') {
            steps {
                bat '''
                    set IDF_TOOLS_PATH=C:\\Users\\omkar\\.espressif
                    set IDF_PATH=C:\\esp\\v6.0.1\\esp-idf
                    set IDF_PYTHON_ENV_PATH=C:\\Users\\omkar\\.espressif\\python_env\\idf6.0_py3.13_env

                    call C:\\esp\\v6.0.1\\esp-idf\\export.bat

                    python --version
                    idf.py --version
                    idf.py build
                '''
            }
        }
    }
}
