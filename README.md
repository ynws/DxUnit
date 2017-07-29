# DxUnit
DxLib + UnitTest�̊���{�ݒ�
�ȑO��������̂��o�[�W�����A�b�v�œ����Ȃ��Ȃ����̂ō�蒼��

## �O��
jenkins�T�[�o�ɂ�  
https://github.com/ynws/jenkinsCCI  
���g�p���Ă���

## �ʐݒ�
���̃��|�W�g�����x�[�X�ɐV�K�ɍ쐬����ꍇ�A�r���h�V�F���̏C�����K�v

UnitTest.sh�̈ȉ��̍s��DxUnit�𐳂������|�W�g�����ɏ���������

```
cd /var/jenkins_home/workspace/DxUnit/
...
gcovr -r ~/workspace/DxUnit/MainLib --xml --output=Coverage.xml .
```

## jenkins�ݒ�
* �r���h�V�F��
    sh UnitTest.sh
* �J�o���b�W���|�[�g�Ώ�
    build/Coverage.xml
* �e�X�g���ʏW�v�Ώ�
    build/testresult.xml

## ��
* Dxlib�T���v��������
* �T���v�����N���X����
* GoogleTest������
* GoogleTest���s
* jenkins��UnitTest
* jenkins��coverage�\��

## TODO
* Release�r���h
* x64�r���h
* GitHub�u�����`�Ď���jenkins�r���h

* Dxlib�g�p�\�[�X�̃e�X�g
    -> �Ƃ������ADxlib�֐��g���Ă�N���X�̓e�X�g�ΏۂƂ��ׂ��Ȃ̂��H
    ���ˑ��R�[�h�͕ʌ��ɂ܂Ƃ߂Ă�������

+ Main
    ���ˑ��B�Ⴆ��Dxlib�g���Ƃ��A�ʂ̉摜���C�u�����g���Ƃ���
    �����Ő؂�ւ���B�\�[�X�ʏ��Ȃ�
    ���C�����W�b�N��MainLib�ĂԂ���
+ MainLib
    �����ˑ��̃��W�b�N
+ UnitTest
    MainLib�̃e�X�g

### UI�������ǂ��؂�ւ���H
* ��1
    Lib��UI�p�֐��Q�̃C���^�[�t�F�[�X������obj��n��
    -> �Ȃ񂩃_�T��
* ��2
    ������MVC�ō��
    M = lib
    V = dxlib
    C = ?
