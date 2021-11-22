## Github 사용법
### Repo link https://github.com/KNU-SYS3/SystemProgramming_TEAM3.git 으로 변경된거에요.  
>1. Git 설치 [https://git-scm.com/downloads](https://git-scm.com/downloads)
>2. Git bash 나 Git CMD 사용
>3. Git Clone -> 자신이 작업하고 싶은 폴더를 만들어서 cmd로 cd {폴더} 후 명령어 입력

```
->자신의 작업 폴더를 정하고 repo 내려받기, 처음 세팅할 때만 입력

$git clone https://github.com/KNU-SYS3/SystemProgramming_TEAM3.git
```

![https://user-images.githubusercontent.com/84179188/142755918-b1ee59d7-b5bd-4295-b056-93ada21a38b8.png](https://user-images.githubusercontent.com/84179188/142755918-b1ee59d7-b5bd-4295-b056-93ada21a38b8.png)
------------
>4. branch 설정

```
##clone한 폴더 안에 .git 폴더가 존재하는 폴더(SystemProgramming_TEAM3) 로 다시 cd 이후에 작업
git branch   --> 현재 branch들 보기

->본인 branch 만들기. 이 branch로 push/pull 작업 수행
git branch {하고 싶은 이름}

->본인 branch로 상태 변경
git checkout {자신의 branch name}
```

![https://user-images.githubusercontent.com/84179188/142755956-61187d1e-dfe0-441e-b8ab-962d67adc480.png](https://user-images.githubusercontent.com/84179188/142755956-61187d1e-dfe0-441e-b8ab-962d67adc480.png)
------------
>5. 수정 후 push 

```
1. 수정 사항 변경 (일부만)

git add {파일}                  // 여러 파일 가능-> git add {파일} {파일}
git commit -m {"text"}         // text에는 아무 말이나 쓰는 것 가능
git push origin {branch name} //본인 branch name 으로..
```


![본인 작업 환경에서 수정](https://user-images.githubusercontent.com/84179188/142756128-f82d0016-68da-4d83-9aac-d68f52327dc0.png)


![변경 명령어](https://user-images.githubusercontent.com/84179188/142756135-31233d07-742d-4793-aad0-c834491ce6ec.png)


![깃허브에 반영된 모습](https://user-images.githubusercontent.com/84179188/142756122-b27bcbc5-c780-44c4-8217-7d4784a61876.png)

------------
   (a.html 을 삭제하고 b.js를 추가한 모습)
![a.html 을 삭제하고 b.js를 추가한 모습](https://user-images.githubusercontent.com/84179188/142756198-415712c6-8da7-437d-8577-8d674360c7be.png)


![변경 명령어 (파일 2개 add)](https://user-images.githubusercontent.com/84179188/142756208-fafc505b-d81b-4410-8f32-51dd25520669.png)


![깃허브에 반영된 모습](https://user-images.githubusercontent.com/84179188/142756182-e41c30c9-40a2-4108-ae0b-c0c146967e3e.png)

------------
```
2. 수정 사항 전부 변경할 때

git add .     //add . 사용시 수정사항 전부 반영 -> 파일 삭제된 것까지 반영함
git commit -m {"text"}
git push origin {branch name}
```


![변경한 파일이 여러 개일 때](https://user-images.githubusercontent.com/84179188/142756289-3b7e7d11-fe47-4030-8dd9-9aba71a2a503.png)


![변경 명령어](https://user-images.githubusercontent.com/84179188/142756296-0407d45c-47bd-4531-9aa6-838ee000c3f0.png)


![깃허브에 반영된 모습](https://user-images.githubusercontent.com/84179188/142756278-72efa7dc-6c52-4278-be94-358686319736.png)

------------
>6. 최신 상태 pull로 내려받기

```
git pull origin main  // 본인 branch인 상태에서 명령어
```

현재 pull.c 가 추가된 상황이지만,
![현재 pull.c 가 추가된 상황이지만,](https://user-images.githubusercontent.com/84179188/142757405-0272b227-618e-4797-bbe1-85343072f61b.png)

내 작업 공간에서는 설정이 되지 않은 상태.
![내 작업 공간에서는 설정이 되지 않은 상태.](https://user-images.githubusercontent.com/84179188/142757416-8ed73de1-9a9a-47c9-8f46-d81189dd2470.png)

git pull origin main / main branch에 있는 내용 내 작업 공간으로 내려받기
![git pull origin main / main branch에 있는 내용 내 작업 공간으로 내려받기](https://user-images.githubusercontent.com/84179188/142757443-409d2547-16f6-412b-b7df-4ccd2f289dcf.png)

작업 공간에 pull.c 가 추가된 모습
![작업 공간에 pull.c 가 추가된 모습](https://user-images.githubusercontent.com/84179188/142757452-1d4d3ddb-ab59-4ff1-b6aa-8c8c621a07eb.png)

------------
>7. 병합 요청하기 / 수정 사항 반영하는 법


 1. 깃허브 들어가기

[https://github.com/KNU-SYS3/SystemProgramming_TEAM3.git](https://github.com/KNU-SYS3/SystemProgramming_TEAM3.git)

 2. 코드 수정 후 push 했다면 pull request 들어가기

![Untitled](https://user-images.githubusercontent.com/84179188/142757464-3c7bc34c-8fce-4dda-ab5e-6e9f9caa486a.png)

 3. New pull request 클릭 

![Untitled](https://user-images.githubusercontent.com/84179188/142757469-9ac4f614-f7af-4334-b109-88c8a48b6735.png)

 4. 이후 본인 branch에 들어가기

![Untitled](https://user-images.githubusercontent.com/84179188/142757475-9f3bd5f4-8bfc-45f5-bcae-b46d21967295.png)

 5. Create pull request 클릭 후 코멘트는 선택 →  Create pull request!

![Untitled](https://user-images.githubusercontent.com/84179188/142757488-b8d7d4fe-9fe5-4d29-a774-1439befc5905.png)

 6. merge 과정 기다리고 merge pull request 클릭 → confirm 하기

![Untitled](https://user-images.githubusercontent.com/84179188/142757497-5ee01504-4266-4a24-8222-ace69fb5811c.png)

 7. merge 확인 후 적용된 것 확인

![앞에서 했던 파일들 다 삭제한거에요](https://user-images.githubusercontent.com/84179188/142757504-1fcc3e53-73b3-4606-afa8-0bff9f5f20eb.png)

(앞에서 했던 파일들 다 삭제한거에요)
