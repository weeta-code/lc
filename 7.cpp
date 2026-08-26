int findKthlargest(vector<int>& nums, int k) {
  priority_queue<int> hp;
  for (auto& num : nums) {
    if (hp.size() >= k) {
      hp.pop();
    }
    hp.push(num);
  }
  return hp.top();
}

/*
  []

  [2]

  [2, 3] 

  [1, 2, 3]
  [2, 3]

  [1, 2, 3]
  [2, 3]

  [2, 3, 5]
  [3, 5]

  [5, 5]

  [4, 5, 5]

  [3]

  [2, 3]
  [1, 2, 3]
  [2, 3]

  [2, 3, 5]
  [3, 5]

  [3,5,6]
  [5, 6]

  [4, 5, 6]


  [2]
  [2, 3]

*/
