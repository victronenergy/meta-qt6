DESCRIPTION ?= "Qt is a cross-platform application development framework for desktop, embedded and mobile."
HOMEPAGE ?= "https://www.qt.io"

QT_MODULE ?= "${BPN}"
QT_MODULE_BRANCH ?= "6.2"
QT_MODULE_BRANCH_PARAM ?= "branch=${QT_MODULE_BRANCH}"

SRC_URI = "${QT_GIT}/${QT_GIT_PROJECT}/${QT_MODULE}.git;name=${QT_MODULE};${QT_MODULE_BRANCH_PARAM};protocol=${QT_GIT_PROTOCOL}"

CVE_PRODUCT = "qt"

S = "${WORKDIR}/git"

PV = "6.2.3"

SRCREV = "${SRCREV_${QT_MODULE}}"

SRCREV_tqtc-qmlcompilerplus = "1b14f233eac6ded41f0e1abc6d2b54f5d4d258c3"
SRCREV_qt3d = "54011d69f17eae299f81205a12c5b3dd280bec15"
SRCREV_qt3d-assimp = "5a38cd0a03015ceabbd5bc6efb0730dde1ef74e5"
SRCREV_qt5compat = "8309a3eb2a884c4d4e6691ef4d5c672d9518926c"
SRCREV_qtbase = "48a1fc1cba99cde6ac6cb3fe2f827b00f989bf4b"
SRCREV_qtcharts = "5209a2a446c3d9de8d5d50902203421bcba0489b"
SRCREV_qtcoap = "93e9a24d325278eade0ea9e5e4d575cd727d6985"
SRCREV_qtconnectivity = "da848df253adbe5f445d542e72605e788bbdf06e"
SRCREV_qtdatavis3d = "a55e93db7a9a69a6dcf64f8df78228c7584c15a5"
SRCREV_qtdeclarative = "c9518ea703fa1fd739e8f7cdbe2cbc1aa46cf205"
SRCREV_qtdeviceutilities = "b6ff504fab5efc2692c0adac7fc64e729011f625"
SRCREV_qtimageformats = "9c5aa280c1df6e161b25f5b0c1a1a7d7b0ddb51c"
SRCREV_qtlottie = "734dd09b28551859ad4d2208354cce11cf347058"
SRCREV_qtmqtt = "bb2dc4195dfe45008de883a7d0e85d8bc0a239b5"
SRCREV_qtmultimedia = "98336f92b84a8ecfde5cc01622471086579cfa52"
SRCREV_qtnetworkauth = "a4b5e05952361f5793e5d58e5bc0158a4bca09ac"
SRCREV_qtopcua = "ede77b2608258bbfa7f758adb18d8401cfc1d2e2"
SRCREV_qtpositioning = "1c2b25d93ab49662427e9bd1e83bafba358ba5f3"
SRCREV_qtquick3d = "28720254946fdcff356377ffffee5d0fc91fdbdf"
SRCREV_qtquick3d-assimp = "5a38cd0a03015ceabbd5bc6efb0730dde1ef74e5"
SRCREV_qtquickdesigner-components = "e2a65b30c08b2614af09645d3e423b9e2255d644"
SRCREV_qtquicktimeline = "ee933a0786b2393018c993115d73965edad718b5"
SRCREV_qtremoteobjects = "e28086bb0663c7dcc3285bf7310ee14a13ace75f"
SRCREV_qtscxml = "78815f7c5b786a2e6d9bb4cf725d02e418a0282b"
SRCREV_qtsensors = "0e07c707896028c1c48537f7880fdb4256ea8958"
SRCREV_qtserialbus = "11424a27e5f12b66e68ab85b7d9acd2e98e2798e"
SRCREV_qtserialport = "5725846bbd3342088f3e395bb83c0a2a677dda08"
SRCREV_qtshadertools = "1e1fc90fbcb03ea4c1bdd4eb43e0fb6bbd3cc9a8"
SRCREV_qtspeech = "462c3384467cec55a31fde11afb959321063a0ce"
SRCREV_qtsvg = "2baaa9b4791ef8ae79478ba00eaf65691540953b"
SRCREV_qttools = "a04fb2bbd5c556e90d40b3ecd6de1ac6be06466d"
SRCREV_qttools-qlitehtml = "4931b7aa30f256c20573d283561aa432fecf8f38"
SRCREV_qttools-qlitehtml-litehtml = "6236113734bb0a28467e5999e86fdd2834be8e01"
SRCREV_qttranslations = "d54b6900061de2b1e52dd9b11805a268bffd736f"
SRCREV_qtvirtualkeyboard = "e7cc57dec8fcb7d524cf56b296f06402cc47fcac"
SRCREV_qtwayland = "56fdbe55bd89c2d625d71b62f9585721f1ddf129"
SRCREV_qtwebchannel = "25908f00d54820b93c6bd777846016acfbb776c6"
SRCREV_qtwebengine = "0e24a0d43561c6c296bc5c6215d311e95875483b"
SRCREV_qtwebengine-chromium = "39aa0ea99a30c9c15fb3640fe9a2638982548c0b"
SRCREV_qtwebsockets = "f7d7f3f599100fd2361c1228a797658de10e69e9"
SRCREV_qtwebview = "3c320ac9ead69dde75a1332060f040d8f7ad2cca"
